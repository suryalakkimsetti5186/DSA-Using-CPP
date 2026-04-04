const BOARD_SIZE = 10;
const TOTAL_SQUARES = BOARD_SIZE * BOARD_SIZE;

// Gravity-defying snakes (go up) and ladders (drifting sideways/chaotic)
const SPECIAL_MOVES = {
    14: { end: 48, type: 'snake' }, // standard snake would go down, this goes up
    30: { end: 75, type: 'snake' },
    55: { end: 92, type: 'snake' },
    21: { end: 28, type: 'ladder' }, // sideways horizontal
    61: { end: 68, type: 'ladder' },
    82: { end: 42, type: 'ladder' }, // wormhole (drops down unexpectedly)
};

const state = {
    players: [
        { id: 1, position: 0, element: null, color: 'var(--p1-color)' },
        { id: 2, position: 0, element: null, color: 'var(--p2-color)' }
    ],
    currentPlayerIndex: 0,
    isRolling: false,
};

// DOM Elements
const boardEl = document.getElementById('board');
const svgLayer = document.getElementById('connections-layer');
const playersLayer = document.getElementById('players-layer');
const rollButton = document.getElementById('roll-button');
const diceEl = document.getElementById('dice');
const statusText = document.getElementById('status-text');
const gameLog = document.getElementById('game-log');

// Map square index (1-100) to its DOM element
const squareElements = {};

function initBoard() {
    let html = '';
    // Generate squares zig-zag from bottom (1) to top (100)
    for (let row = BOARD_SIZE - 1; row >= 0; row--) {
        const isEventRow = row % 2 !== 0;
        let startCol = isEventRow ? BOARD_SIZE - 1 : 0;
        let step = isEventRow ? -1 : 1;
        
        for (let col = 0; col < BOARD_SIZE; col++) {
            const num = row * BOARD_SIZE + (isEventRow ? (BOARD_SIZE - col) : (col + 1));
            html += `<div class="square" id="sq-${num}">${num}</div>`;
        }
    }
    boardEl.innerHTML = html;

    // Cache elements and render connections
    setTimeout(() => {
        for (let i = 1; i <= TOTAL_SQUARES; i++) {
            squareElements[i] = document.getElementById(`sq-${i}`);
        }
        drawConnections();
        initPlayers();
    }, 100);
}

function drawConnections() {
    svgLayer.innerHTML = '';
    
    // We need board bounding box to calculate relative positions
    const boardRect = boardEl.getBoundingClientRect();

    Object.keys(SPECIAL_MOVES).forEach(startStr => {
        const start = parseInt(startStr);
        const { end, type } = SPECIAL_MOVES[start];
        
        const startSq = squareElements[start];
        const endSq = squareElements[end];

        if (!startSq || !endSq) return;

        const x1 = startSq.offsetLeft + startSq.offsetWidth / 2;
        const y1 = startSq.offsetTop + startSq.offsetHeight / 2;
        const x2 = endSq.offsetLeft + endSq.offsetWidth / 2;
        const y2 = endSq.offsetTop + endSq.offsetHeight / 2;

        const path = document.createElementNS('http://www.w3.org/2000/svg', 'path');
        path.setAttribute('class', `path-line ${type}-line`);

        // Create a bezier curve
        const midX = (x1 + x2) / 2 + (Math.random() * 100 - 50);
        const midY = (y1 + y2) / 2 + (Math.random() * 100 - 50);
        
        const pathData = `M ${x1} ${y1} Q ${midX} ${midY} ${x2} ${y2}`;
        path.setAttribute('d', pathData);
        
        svgLayer.appendChild(path);
    });
}

function initPlayers() {
    state.players.forEach(p => {
        const piece = document.createElement('div');
        piece.className = `player-piece player${p.id}-piece`;
        playersLayer.appendChild(piece);
        p.element = piece;
        updatePlayerVisual(p, true);
    });
}

function updatePlayerVisual(player, initial = false) {
    if (player.position === 0) {
        // Render slightly off-board initially
        const sq1 = squareElements[1];
        if (sq1) {
            player.element.style.transform = `translate3d(${sq1.offsetLeft - 40}px, ${sq1.offsetTop + 40 + (player.id * 20)}px, 40px)`;
        }
        return;
    }

    const sq = squareElements[player.position];
    if (sq) {
        // Add random slight offset so pieces don't perfectly overlap
        const offset = player.id === 1 ? -10 : 10;
        // Transform includes isometric mapping handling
        player.element.style.transform = `translate3d(${sq.offsetLeft + sq.offsetWidth / 2 + offset}px, ${sq.offsetTop + sq.offsetHeight / 2 + offset}px, 60px)`;
    }
}

function logMessage(msg) {
    const p = document.createElement('p');
    p.innerText = msg;
    gameLog.prepend(p);
}

function rollDice() {
    if (state.isRolling) return;
    state.isRolling = true;
    rollButton.disabled = true;

    // The slowmo dice roll effect
    const rollValue = Math.floor(Math.random() * 6) + 1;
    
    // Calculate rotations to show the correct face
    let rX = 0, rY = 0;
    switch(rollValue) {
        case 1: rX = 0; rY = 0; break;     // Front
        case 2: rX = -90; rY = 0; break;   // Top
        case 3: rX = 0; rY = -90; break;   // Right
        case 4: rX = 0; rY = 90; break;    // Left
        case 5: rX = 90; rY = 0; break;    // Bottom
        case 6: rX = 0; rY = -180; break;  // Back
    }

    // Add extra spins for mid-air effect
    rX += 720;
    rY += 720;

    diceEl.style.transform = `translateZ(-40px) rotateX(${rX}deg) rotateY(${rY}deg)`;
    logMessage(`Roll initiated... folding space...`);

    // Wait for the slow rotation to finish
    setTimeout(() => {
        // Reset transform to low degrees so it doesn't spin infinitely large numbers
        diceEl.style.transition = 'none';
        diceEl.style.transform = `translateZ(-40px) rotateX(${rX % 360}deg) rotateY(${rY % 360}deg)`;
        setTimeout(() => diceEl.style.transition = 'transform 3s cubic-bezier(0.1, 0.6, 0.3, 1)', 50);

        handleMove(rollValue);
    }, 3000); // matches the 3s css transition
}

function handleMove(rollValue) {
    const p = state.players[state.currentPlayerIndex];
    let newPos = p.position + rollValue;
    
    logMessage(`Player ${p.id} lands on ${rollValue}. Moves to ${newPos}.`);

    if (newPos > TOTAL_SQUARES) {
        logMessage(`Player ${p.id} deflected by gravity wall! Bounces back.`);
        newPos = TOTAL_SQUARES - (newPos - TOTAL_SQUARES);
    }

    p.position = newPos;
    updatePlayerVisual(p);

    setTimeout(() => {
        // Check for snadders and ladderakes
        if (SPECIAL_MOVES[p.position]) {
            const move = SPECIAL_MOVES[p.position];
            logMessage(`Caught in a ${move.type} anomaly! Warping to ${move.end}.`);
            p.position = move.end;
            updatePlayerVisual(p);
            
            setTimeout(() => checkWin(p), 1200); // delay after secondary move
        } else {
            checkWin(p);
        }
    }, 1200); // delay after primary move (1s transition)
}

function checkWin(p) {
    if (p.position === TOTAL_SQUARES) {
        logMessage(`Player ${p.id} HAS ASCENDED. GAME OVER.`);
        showWinScreen(p.id);
        return;
    }
    
    // Switch Turn
    state.currentPlayerIndex = state.currentPlayerIndex === 0 ? 1 : 0;
    const nextP = state.players[state.currentPlayerIndex];
    
    statusText.innerText = `Player ${nextP.id}'s Turn`;
    statusText.style.color = nextP.color;
    
    state.isRolling = false;
    rollButton.disabled = false;
}

function showWinScreen(winnerId) {
    const div = document.createElement('div');
    div.id = 'win-screen';
    div.innerHTML = `<h2>Player ${winnerId} Ascended!</h2>
                     <button id="roll-button" onclick="location.reload()">Re-enter the Void</button>`;
    document.body.appendChild(div);
    setTimeout(() => div.classList.add('visible'), 100);
}

// Event Listeners
rollButton.addEventListener('click', rollDice);

// Init
initBoard();
