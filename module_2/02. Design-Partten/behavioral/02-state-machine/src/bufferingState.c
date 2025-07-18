#include <stdio.h>
#include <stdlib.h>
#include "pausedState.h"
#include "playerState.h"
#include "stoppedState.h"
#include "musicPlayer.h"
#include "bufferingState.h"

// Forward declaration
static void pressPlay(PlayerState* state);
static void pressPause(PlayerState* state);
static void pressStop(PlayerState* state);
static void setContext(PlayerState* state, struct MusicPlayer* player);

PlayerState* bufferingStateCreate() {
    PlayerState *state = (PlayerState*)malloc(sizeof(PlayerState));
    state->pressPlay = pressPlay;
    state->pressPause = pressPause;
    state->pressStop = pressStop;
    state->setContext = setContext;
    state->player = NULL;
    
    return state;
}

static void pressPlay(PlayerState *state) {
    printf("Buffering... Please wait!\n");
}

static void pressPause(PlayerState *state) {
    printf("Buffering canceled. Going to Paused state.\n");
    state->player->changeState(state->player, pausedStateCreate());
}

static void pressStop(PlayerState *state) {
    printf("Buffering canceled. Going to Stopped state.\n");
    state->player->changeState(state->player, stoppedStateCreate());
}

static void setContext(PlayerState *state, struct MusicPlayer *player) {
    state->player = player;
}