#ifndef UBERCASINOSPLTYPES_H
#define UBERCASINOSPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "ccpp_UberCasino.h"


extern c_metaObject __UberCasino_UberCasino__load (c_base base);

extern c_metaObject __UberCasino_suite_t__load (c_base base);
enum _UberCasino_suite_t {
    _UberCasino_hearts,
    _UberCasino_diamonds,
    _UberCasino_clubs,
    _UberCasino_spades
};

extern c_metaObject __UberCasino_card_kind__load (c_base base);
enum _UberCasino_card_kind {
    _UberCasino_ace,
    _UberCasino_two,
    _UberCasino_three,
    _UberCasino_four,
    _UberCasino_five,
    _UberCasino_six,
    _UberCasino_seven,
    _UberCasino_eight,
    _UberCasino_nine,
    _UberCasino_ten,
    _UberCasino_jack,
    _UberCasino_queen,
    _UberCasino_king
};

extern const char *UberCasino_card_t_metaDescriptor[];
extern const int UberCasino_card_t_metaDescriptorArrLength;
extern const int UberCasino_card_t_metaDescriptorLength;
extern c_metaObject __UberCasino_card_t__load (c_base base);
struct _UberCasino_card_t ;
extern  v_copyin_result __UberCasino_card_t__copyIn(c_base base, const struct UberCasino::card_t *from, struct _UberCasino_card_t *to);
extern  void __UberCasino_card_t__copyOut(const void *_from, void *_to);
struct _UberCasino_card_t {
    enum _UberCasino_card_kind card;
    enum _UberCasino_suite_t suite;
    c_bool valid;
};

extern c_metaObject __UberCasino_player_action_t__load (c_base base);
enum _UberCasino_player_action_t {
    _UberCasino_idle,
    _UberCasino_hitting,
    _UberCasino_standing,
    _UberCasino_splitting,
    _UberCasino_doubling
};

extern const char *UberCasino_Player_metaDescriptor[];
extern const int UberCasino_Player_metaDescriptorArrLength;
extern const int UberCasino_Player_metaDescriptorLength;
extern c_metaObject __UberCasino_Player__load (c_base base);
struct _UberCasino_Player ;
extern  v_copyin_result __UberCasino_Player__copyIn(c_base base, const struct UberCasino::Player *from, struct _UberCasino_Player *to);
extern  void __UberCasino_Player__copyOut(const void *_from, void *_to);
struct _UberCasino_Player {
    c_long count;
    c_char uid[16];
    c_char game_uid[16];
    c_char name[32];
    c_float balance;
    enum _UberCasino_player_action_t A;
};

extern c_metaObject __UberCasino_game_state__load (c_base base);
enum _UberCasino_game_state {
    _UberCasino_waiting_to_join,
    _UberCasino_waiting,
    _UberCasino_playing,
    _UberCasino_end_hand
};

extern const char *UberCasino_Dealer_metaDescriptor[];
extern const int UberCasino_Dealer_metaDescriptorArrLength;
extern const int UberCasino_Dealer_metaDescriptorLength;
extern c_metaObject __UberCasino_Dealer__load (c_base base);
struct _UberCasino_Dealer ;
extern  v_copyin_result __UberCasino_Dealer__copyIn(c_base base, const struct UberCasino::Dealer *from, struct _UberCasino_Dealer *to);
extern  void __UberCasino_Dealer__copyOut(const void *_from, void *_to);
struct _UberCasino_Dealer {
    c_char uid[16];
    c_char name[32];
    c_char game_uid[16];
};

extern const char *UberCasino_PlayerState_metaDescriptor[];
extern const int UberCasino_PlayerState_metaDescriptorArrLength;
extern const int UberCasino_PlayerState_metaDescriptorLength;
extern c_metaObject __UberCasino_PlayerState__load (c_base base);
struct _UberCasino_PlayerState ;
extern  v_copyin_result __UberCasino_PlayerState__copyIn(c_base base, const struct UberCasino::PlayerState *from, struct _UberCasino_PlayerState *to);
extern  void __UberCasino_PlayerState__copyOut(const void *_from, void *_to);
struct _UberCasino_PlayerState {
    c_char uid[16];
    struct _UberCasino_card_t cards[10];
};

extern const char *UberCasino_Game_metaDescriptor[];
extern const int UberCasino_Game_metaDescriptorArrLength;
extern const int UberCasino_Game_metaDescriptorLength;
extern c_metaObject __UberCasino_Game__load (c_base base);
struct _UberCasino_Game ;
extern  v_copyin_result __UberCasino_Game__copyIn(c_base base, const struct UberCasino::Game *from, struct _UberCasino_Game *to);
extern  void __UberCasino_Game__copyOut(const void *_from, void *_to);
struct _UberCasino_Game {
    enum _UberCasino_game_state gstate;
    c_char game_uid[16];
    c_char dealer_uid[16];
    struct _UberCasino_PlayerState p[7];
    struct _UberCasino_card_t dealer_cards[10];
    c_long active_player;
};

#undef OS_API
#endif
