// Zero-G Chase core game logic
const canvas = document.getElementById('game-canvas');
const ctx = canvas.getContext('2d');

let cw = window.innerWidth;
let ch = window.innerHeight;
canvas.width = cw;
canvas.height = ch;

// UI Elements
const mainMenu = document.getElementById('main-menu');
const gameHud = document.getElementById('game-hud');
const gameOverMenu = document.getElementById('game-over');
const startBtn = document.getElementById('start-btn');
const restartBtn = document.getElementById('restart-btn');
const scoreVal = document.getElementById('score-val');
const enforcerDist = document.getElementById('enforcer-dist');
const finalScore = document.getElementById('final-score');

// Game State
let gameState = 'MENU'; // MENU, PLAYING, GAMEOVER
let cameraX = 0;
let cameraY = 0;
let distance = 0;
let mouseX = cw / 2;
let mouseY = ch / 2;
let isMouseDown = false;

// Entities
let player = { x: 200, y: ch / 2, vx: 200, vy: 0, radius: 15 };
let enforcer = { x: -300, y: ch / 2, speed: 220 }; // Enforcer base speed
let anchors = [];
let particles = [];
let web = { active: false, target: null };

// Colors
const COLOR_HERO = '#00ffff';
const COLOR_ENFORCER = '#ff0055';
const COLOR_ANCHOR = '#a0c0f0';
const COLOR_WEB = 'rgba(0, 255, 255, 0.6)';

// Event Listeners
window.addEventListener('resize', () => {
    cw = window.innerWidth;
    ch = window.innerHeight;
    canvas.width = cw;
    canvas.height = ch;
});

function updateMouse(e) {
    if (e.touches) {
        mouseX = e.touches[0].clientX;
        mouseY = e.touches[0].clientY;
    } else {
        mouseX = e.clientX;
        mouseY = e.clientY;
    }
}

window.addEventListener('mousemove', updateMouse);
window.addEventListener('mousedown', (e) => { isMouseDown = true; updateMouse(e); });
window.addEventListener('mouseup', () => isMouseDown = false);
window.addEventListener('touchstart', (e) => { isMouseDown = true; updateMouse(e); }, { passive: false });
window.addEventListener('touchmove', (e) => { updateMouse(e); e.preventDefault(); }, { passive: false });
window.addEventListener('touchend', () => isMouseDown = false);

startBtn.addEventListener('click', startGame);
restartBtn.addEventListener('click', startGame);

function startGame() {
    gameState = 'PLAYING';
    mainMenu.classList.remove('active');
    setTimeout(() => mainMenu.classList.add('hidden'), 400);
    gameOverMenu.classList.remove('active');
    setTimeout(() => gameOverMenu.classList.add('hidden'), 400);
    
    gameHud.classList.remove('hidden');
    
    initGame();
}

function gameOver() {
    gameState = 'GAMEOVER';
    gameHud.classList.add('hidden');
    gameOverMenu.classList.remove('hidden');
    setTimeout(() => gameOverMenu.classList.add('active'), 50);
    finalScore.innerText = distance;
}

function initGame() {
    cameraX = 0;
    cameraY = 0;
    distance = 0;
    
    player = { x: 200, y: ch / 2, vx: 300, vy: 0, radius: 15 };
    enforcer = { x: -500, y: ch / 2, speed: 280 };
    anchors = [];
    particles = [];
    web = { active: false, target: null };

    // Initial debris
    for(let i = 0; i < 30; i++) {
        anchors.push(createAnchor(300 + Math.random() * 2000));
    }
}

function createAnchor(x) {
    return {
        x: x,
        y: (Math.random() - 0.5) * ch * 2 + ch / 2,
        radius: 8 + Math.random() * 25,
        driftY: (Math.random() - 0.5) * 20
    };
}

function createParticle(x, y, color, speed, duration) {
    particles.push({
        x, y,
        vx: (Math.random() - 0.5) * speed,
        vy: (Math.random() - 0.5) * speed,
        life: duration,
        maxLife: duration,
        color,
        size: Math.random() * 4 + 1
    });
}

function update(dt) {
    if (gameState !== 'PLAYING') return;
    const dts = Math.min(dt / 1000, 0.1); // cap dt to prevent huge jumps

    // Auto drift player to right if too slow
    if (player.vx < 150) player.vx += 300 * dts;
    
    player.x += player.vx * dts;
    player.y += player.vy * dts;
    
    // Bounds check to keep rough verticality
    const verticalLimit = ch * 1.5;
    if (player.y < -verticalLimit) { player.y = -verticalLimit; player.vy *= -0.5; }
    if (player.y > ch + verticalLimit) { player.y = ch + verticalLimit; player.vy *= -0.5; }
    
    // Minimal friction simulating zero-g drag
    player.vx *= 0.995;
    player.vy *= 0.995;
    
    // Web Logic
    if (isMouseDown) {
        if (!web.active) {
            let worldMouseX = mouseX + cameraX;
            let worldMouseY = mouseY + cameraY;
            
            let bestDist = Infinity;
            let bestAnchor = null;
            
            for (let a of anchors) {
                let dx = a.x - worldMouseX;
                let dy = a.y - worldMouseY;
                let dist = Math.sqrt(dx*dx + dy*dy);
                // Can grab within 300px of mouse cursor
                if (dist < 300 && dist < bestDist) {
                    bestDist = dist;
                    bestAnchor = a;
                }
            }
            if (bestAnchor) {
                web.active = true;
                web.target = bestAnchor;
            }
        }
        
        if (web.active && web.target) {
            let dx = web.target.x - player.x;
            let dy = web.target.y - player.y;
            let dist = Math.sqrt(dx*dx + dy*dy);
            
            if (dist > 10) {
                let force = 800; // Pull strength
                player.vx += (dx / dist) * force * dts;
                player.vy += (dy / dist) * force * dts;
            }
            // Generate spark
            if (Math.random() < 0.2) {
                createParticle(web.target.x, web.target.y, COLOR_HERO, 50, 0.5);
            }
        }
    } else {
        web.active = false;
        web.target = null;
    }
    
    // Camera follow (smooth)
    let targetCamX = player.x - cw * 0.3; // keep player on left side
    let targetCamY = player.y - ch * 0.5;
    cameraX += (targetCamX - cameraX) * 5 * dts;
    cameraY += (targetCamY - cameraY) * 5 * dts;
    if (cameraX < targetCamX - 100) cameraX = targetCamX - 100;

    // Camera rumble based on speed
    const currentSpeed = Math.sqrt(player.vx * player.vx + player.vy * player.vy);
    if(currentSpeed > 600) {
        cameraX += (Math.random() - 0.5) * 5;
        cameraY += (Math.random() - 0.5) * 5;
    }
    
    // Enforcer logic
    enforcer.speed += 5 * dts; // Speed increases gradually
    enforcer.x += enforcer.speed * dts;
    let dyEnforcer = player.y - enforcer.y;
    enforcer.y += dyEnforcer * 1.5 * dts; // Home in on Y axis with smoothing
    
    // Enforcer Thrusters
    createParticle(enforcer.x - 20, enforcer.y, COLOR_ENFORCER, 100, 0.6);
    
    if (enforcer.x + 30 > player.x - player.radius) {
        createParticle(player.x, player.y, COLOR_ENFORCER, 500, 2);
        gameOver();
    }
    
    // Update anchors & environment
    let rightBound = cameraX + cw + 800;
    while(anchors.length > 0 && anchors[0].x < cameraX - 500) {
        anchors.shift(); // Remove passed anchors
    }
    
    let lastAnchorX = anchors.length > 0 ? anchors[anchors.length-1].x : player.x;
    while(lastAnchorX < rightBound) {
        lastAnchorX += 80 + Math.random() * 250;
        anchors.push(createAnchor(lastAnchorX));
    }
    
    for (let a of anchors) {
        a.y += a.driftY * dts; // Slow drift
    }
    
    // Update particles
    for (let i = particles.length - 1; i >= 0; i--) {
        let p = particles[i];
        p.life -= dts;
        p.x += p.vx * dts;
        p.y += p.vy * dts;
        if (p.life <= 0) particles.splice(i, 1);
    }
    
    // UI Update
    distance = Math.floor(player.x / 10);
    scoreVal.innerText = distance;
    let distToEnforcer = Math.floor((player.x - enforcer.x) / 10);
    if (distToEnforcer < 0) distToEnforcer = 0;
    enforcerDist.innerText = distToEnforcer + "m";
    enforcerDist.style.color = distToEnforcer < 40 ? '#ff0000' : '#ff0055';
}

function drawGrid(ctx) {
    ctx.strokeStyle = 'rgba(0, 255, 255, 0.05)';
    ctx.lineWidth = 1;
    let gridSize = 150;
    let startX = Math.floor(cameraX / gridSize) * gridSize;
    let startY = Math.floor(cameraY / gridSize) * gridSize;
    
    for (let i = startX; i < startX + cw + gridSize; i += gridSize) {
        ctx.beginPath(); ctx.moveTo(i, cameraY); ctx.lineTo(i, cameraY + ch); ctx.stroke();
    }
    for (let i = startY; i < startY + ch + gridSize; i += gridSize) {
        ctx.beginPath(); ctx.moveTo(cameraX, i); ctx.lineTo(cameraX + cw, i); ctx.stroke();
    }
}

function drawBackground() {
    // Basic structural pillars moving at different speeds for parallax
    ctx.fillStyle = 'rgba(20, 30, 60, 0.3)';
    let parallaxScroll = cameraX * 0.3;
    let pSize = 100;
    let startXP = Math.floor(parallaxScroll / 400) * 400;
    
    for(let i = startXP; i < startXP + cw + 400; i += 400) {
        let drawX = i - parallaxScroll + cameraX;
        ctx.fillRect(drawX, cameraY, pSize, ch);
        ctx.fillRect(drawX + 200, cameraY - 200, pSize/2, ch + 400); // Inverse structures
    }
}

function draw() {
    ctx.fillStyle = '#050a15';
    ctx.fillRect(0, 0, cw, ch);
    
    ctx.save();
    ctx.translate(-cameraX, -cameraY);
    
    if (gameState === 'PLAYING') {
        drawBackground();
        drawGrid(ctx);
        
        // Draw Web line
        if (web.active && web.target) {
            ctx.beginPath();
            ctx.moveTo(player.x, player.y);
            // Draw a slightly curved line for dynamic feel
            let midX = (player.x + web.target.x) / 2;
            let midY = (player.y + web.target.y) / 2 + 30; // sag
            ctx.quadraticCurveTo(midX, midY, web.target.x, web.target.y);
            ctx.strokeStyle = COLOR_WEB;
            ctx.lineWidth = 3;
            ctx.stroke();
            
            // Aim indicator
            ctx.beginPath();
            ctx.arc(web.target.x, web.target.y, web.target.radius + 10, 0, Math.PI * 2);
            ctx.strokeStyle = COLOR_HERO;
            ctx.lineWidth = 1;
            ctx.stroke();
        }
        
        // Draw Anchors (Debris)
        for (let a of anchors) {
            ctx.beginPath();
            ctx.arc(a.x, a.y, a.radius, 0, Math.PI * 2);
            ctx.fillStyle = COLOR_ANCHOR;
            ctx.fill();
            // Core
            ctx.beginPath();
            ctx.arc(a.x, a.y, a.radius * 0.4, 0, Math.PI * 2);
            ctx.fillStyle = '#ffffff';
            ctx.fill();
        }
        
        // Draw Enforcer
        ctx.shadowBlur = 20;
        ctx.shadowColor = COLOR_ENFORCER;
        ctx.beginPath();
        ctx.moveTo(enforcer.x + 20, enforcer.y);
        ctx.lineTo(enforcer.x - 20, enforcer.y - 15);
        ctx.lineTo(enforcer.x - 10, enforcer.y);
        ctx.lineTo(enforcer.x - 20, enforcer.y + 15);
        ctx.closePath();
        ctx.fillStyle = COLOR_ENFORCER;
        ctx.fill();
        ctx.shadowBlur = 0; // reset
        
        // Enforcer beam sight
        ctx.beginPath();
        ctx.moveTo(enforcer.x + 20, enforcer.y);
        ctx.lineTo(player.x, player.y);
        ctx.strokeStyle = 'rgba(255, 0, 85, 0.1)';
        ctx.lineWidth = 2;
        ctx.stroke();
        
        // Draw Player
        ctx.shadowBlur = 15;
        ctx.shadowColor = COLOR_HERO;
        ctx.beginPath();
        ctx.arc(player.x, player.y, player.radius, 0, Math.PI * 2);
        ctx.fillStyle = COLOR_HERO;
        ctx.fill();
        // Inner core
        ctx.beginPath();
        ctx.arc(player.x, player.y, player.radius * 0.5, 0, Math.PI * 2);
        ctx.fillStyle = '#fff';
        ctx.fill();
        ctx.shadowBlur = 0;
        
        // Draw Particles
        for (let p of particles) {
            ctx.globalAlpha = p.life / p.maxLife;
            ctx.beginPath();
            ctx.arc(p.x, p.y, p.size, 0, Math.PI * 2);
            ctx.fillStyle = p.color;
            ctx.fill();
        }
        ctx.globalAlpha = 1.0;
    }
    
    ctx.restore();
}

let lastTime = performance.now();
function gameLoop(timestamp) {
    const dt = timestamp - lastTime || 0;
    lastTime = timestamp;
    
    update(dt);
    draw();
    
    requestAnimationFrame(gameLoop);
}

requestAnimationFrame(gameLoop);
