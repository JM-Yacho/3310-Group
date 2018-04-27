#include "UberCasinoSplDcps.h"
#include "ccpp_UberCasino.h"

#include <v_copyIn.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__UberCasino_card_t__copyIn(
    c_base base,
    const struct ::UberCasino::card_t *from,
    struct _UberCasino_card_t *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

#ifdef OSPL_BOUNDS_CHECK
    if((((c_long)from->card) >= 0) && (((c_long)from->card) < 13) ){
        to->card = (enum _UberCasino_card_kind)from->card;
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'UberCasino::card_t.card' of type 'card_kind' is out of range.");
        result = V_COPYIN_RESULT_INVALID;
    }
#else
    to->card = (enum _UberCasino_card_kind)from->card;
#endif
#ifdef OSPL_BOUNDS_CHECK
    if((((c_long)from->suite) >= 0) && (((c_long)from->suite) < 4) ){
        to->suite = (enum _UberCasino_suite_t)from->suite;
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'UberCasino::card_t.suite' of type 'suite_t' is out of range.");
        result = V_COPYIN_RESULT_INVALID;
    }
#else
    to->suite = (enum _UberCasino_suite_t)from->suite;
#endif
    to->valid = (c_bool)from->valid;
    return result;
}

v_copyin_result
__UberCasino_Player__copyIn(
    c_base base,
    const struct ::UberCasino::Player *from,
    struct _UberCasino_Player *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->count = (c_long)from->count;
    {
        typedef c_char _DestType[16];
        _DestType *dest = &to->uid;
        memcpy (dest, from->uid, sizeof (*dest));
    }
    {
        typedef c_char _DestType[16];
        _DestType *dest = &to->game_uid;
        memcpy (dest, from->game_uid, sizeof (*dest));
    }
    {
        typedef c_char _DestType[32];
        _DestType *dest = &to->name;
        memcpy (dest, from->name, sizeof (*dest));
    }
    to->balance = (c_float)from->balance;
#ifdef OSPL_BOUNDS_CHECK
    if((((c_long)from->A) >= 0) && (((c_long)from->A) < 5) ){
        to->A = (enum _UberCasino_player_action_t)from->A;
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'UberCasino::Player.A' of type 'player_action_t' is out of range.");
        result = V_COPYIN_RESULT_INVALID;
    }
#else
    to->A = (enum _UberCasino_player_action_t)from->A;
#endif
    return result;
}

v_copyin_result
__UberCasino_Dealer__copyIn(
    c_base base,
    const struct ::UberCasino::Dealer *from,
    struct _UberCasino_Dealer *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    {
        typedef c_char _DestType[16];
        _DestType *dest = &to->uid;
        memcpy (dest, from->uid, sizeof (*dest));
    }
    {
        typedef c_char _DestType[32];
        _DestType *dest = &to->name;
        memcpy (dest, from->name, sizeof (*dest));
    }
    {
        typedef c_char _DestType[16];
        _DestType *dest = &to->game_uid;
        memcpy (dest, from->game_uid, sizeof (*dest));
    }
    return result;
}

v_copyin_result
__UberCasino_PlayerState__copyIn(
    c_base base,
    const struct ::UberCasino::PlayerState *from,
    struct _UberCasino_PlayerState *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    {
        typedef c_char _DestType[16];
        _DestType *dest = &to->uid;
        memcpy (dest, from->uid, sizeof (*dest));
    }
    {
        typedef struct _UberCasino_card_t _DestType[10];
        _DestType *dest = &to->cards;
        int i1;

        for (i1 = 0; (i1 < 10) && V_COPYIN_RESULT_IS_OK(result); i1++) {
            extern v_copyin_result __UberCasino_card_t__copyIn(c_base base,
    const UberCasino::card_t *From,
    struct _UberCasino_card_t *To);

if(V_COPYIN_RESULT_IS_OK(result)){
                result = __UberCasino_card_t__copyIn(base, (::UberCasino::card_t *)&(from->cards)[i1], (struct _UberCasino_card_t *)&(*dest)[i1]);
            }
        }
    }
    return result;
}

v_copyin_result
__UberCasino_Game__copyIn(
    c_base base,
    const struct ::UberCasino::Game *from,
    struct _UberCasino_Game *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

#ifdef OSPL_BOUNDS_CHECK
    if((((c_long)from->gstate) >= 0) && (((c_long)from->gstate) < 4) ){
        to->gstate = (enum _UberCasino_game_state)from->gstate;
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'UberCasino::Game.gstate' of type 'game_state' is out of range.");
        result = V_COPYIN_RESULT_INVALID;
    }
#else
    to->gstate = (enum _UberCasino_game_state)from->gstate;
#endif
    {
        typedef c_char _DestType[16];
        _DestType *dest = &to->game_uid;
        memcpy (dest, from->game_uid, sizeof (*dest));
    }
    {
        typedef c_char _DestType[16];
        _DestType *dest = &to->dealer_uid;
        memcpy (dest, from->dealer_uid, sizeof (*dest));
    }
    {
        typedef struct _UberCasino_PlayerState _DestType[7];
        _DestType *dest = &to->p;
        int i1;

        for (i1 = 0; (i1 < 7) && V_COPYIN_RESULT_IS_OK(result); i1++) {
            extern v_copyin_result __UberCasino_PlayerState__copyIn(c_base base,
    const UberCasino::PlayerState *From,
    struct _UberCasino_PlayerState *To);

if(V_COPYIN_RESULT_IS_OK(result)){
                result = __UberCasino_PlayerState__copyIn(base, (::UberCasino::PlayerState *)&(from->p)[i1], (struct _UberCasino_PlayerState *)&(*dest)[i1]);
            }
        }
    }
    {
        typedef struct _UberCasino_card_t _DestType[10];
        _DestType *dest = &to->dealer_cards;
        int i1;

        for (i1 = 0; (i1 < 10) && V_COPYIN_RESULT_IS_OK(result); i1++) {
            extern v_copyin_result __UberCasino_card_t__copyIn(c_base base,
    const UberCasino::card_t *From,
    struct _UberCasino_card_t *To);

if(V_COPYIN_RESULT_IS_OK(result)){
                result = __UberCasino_card_t__copyIn(base, (::UberCasino::card_t *)&(from->dealer_cards)[i1], (struct _UberCasino_card_t *)&(*dest)[i1]);
            }
        }
    }
    to->active_player = (c_long)from->active_player;
    return result;
}

void
__UberCasino_card_t__copyOut(
    const void *_from,
    void *_to)
{
    const struct _UberCasino_card_t *from = (const struct _UberCasino_card_t *)_from;
    struct ::UberCasino::card_t *to = (struct ::UberCasino::card_t *)_to;
    to->card = (::UberCasino::card_kind)from->card;
    to->suite = (::UberCasino::suite_t)from->suite;
    to->valid = (::DDS::Boolean)(from->valid != 0);
}

void
__UberCasino_Player__copyOut(
    const void *_from,
    void *_to)
{
    const struct _UberCasino_Player *from = (const struct _UberCasino_Player *)_from;
    struct ::UberCasino::Player *to = (struct ::UberCasino::Player *)_to;
    to->count = (::DDS::Long)from->count;
    {
        typedef c_char _DestType[16];
        const _DestType *src = &from->uid;

        memcpy ((void *)to->uid, src, sizeof (*src));
    }
    {
        typedef c_char _DestType[16];
        const _DestType *src = &from->game_uid;

        memcpy ((void *)to->game_uid, src, sizeof (*src));
    }
    {
        typedef c_char _DestType[32];
        const _DestType *src = &from->name;

        memcpy ((void *)to->name, src, sizeof (*src));
    }
    to->balance = (::DDS::Float)from->balance;
    to->A = (::UberCasino::player_action_t)from->A;
}

void
__UberCasino_Dealer__copyOut(
    const void *_from,
    void *_to)
{
    const struct _UberCasino_Dealer *from = (const struct _UberCasino_Dealer *)_from;
    struct ::UberCasino::Dealer *to = (struct ::UberCasino::Dealer *)_to;
    {
        typedef c_char _DestType[16];
        const _DestType *src = &from->uid;

        memcpy ((void *)to->uid, src, sizeof (*src));
    }
    {
        typedef c_char _DestType[32];
        const _DestType *src = &from->name;

        memcpy ((void *)to->name, src, sizeof (*src));
    }
    {
        typedef c_char _DestType[16];
        const _DestType *src = &from->game_uid;

        memcpy ((void *)to->game_uid, src, sizeof (*src));
    }
}

void
__UberCasino_PlayerState__copyOut(
    const void *_from,
    void *_to)
{
    const struct _UberCasino_PlayerState *from = (const struct _UberCasino_PlayerState *)_from;
    struct ::UberCasino::PlayerState *to = (struct ::UberCasino::PlayerState *)_to;
    {
        typedef c_char _DestType[16];
        const _DestType *src = &from->uid;

        memcpy ((void *)to->uid, src, sizeof (*src));
    }
    {
        typedef struct _UberCasino_card_t _DestType[10];
        const _DestType *src = &from->cards;

        int i1;

        for (i1 = 0; (i1 < 10); i1++) {
            extern void __UberCasino_card_t__copyOut(const void *, void *);
            __UberCasino_card_t__copyOut((const void *)&(*src)[i1], (void *)&(to->cards)[i1]);
        }
    }
}

void
__UberCasino_Game__copyOut(
    const void *_from,
    void *_to)
{
    const struct _UberCasino_Game *from = (const struct _UberCasino_Game *)_from;
    struct ::UberCasino::Game *to = (struct ::UberCasino::Game *)_to;
    to->gstate = (::UberCasino::game_state)from->gstate;
    {
        typedef c_char _DestType[16];
        const _DestType *src = &from->game_uid;

        memcpy ((void *)to->game_uid, src, sizeof (*src));
    }
    {
        typedef c_char _DestType[16];
        const _DestType *src = &from->dealer_uid;

        memcpy ((void *)to->dealer_uid, src, sizeof (*src));
    }
    {
        typedef struct _UberCasino_PlayerState _DestType[7];
        const _DestType *src = &from->p;

        int i1;

        for (i1 = 0; (i1 < 7); i1++) {
            extern void __UberCasino_PlayerState__copyOut(const void *, void *);
            __UberCasino_PlayerState__copyOut((const void *)&(*src)[i1], (void *)&(to->p)[i1]);
        }
    }
    {
        typedef struct _UberCasino_card_t _DestType[10];
        const _DestType *src = &from->dealer_cards;

        int i1;

        for (i1 = 0; (i1 < 10); i1++) {
            extern void __UberCasino_card_t__copyOut(const void *, void *);
            __UberCasino_card_t__copyOut((const void *)&(*src)[i1], (void *)&(to->dealer_cards)[i1]);
        }
    }
    to->active_player = (::DDS::Long)from->active_player;
}

