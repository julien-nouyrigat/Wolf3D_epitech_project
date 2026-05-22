/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** flag_h
*/

#include "wolf.h"

static void print_controls(void)
{
    printf("For the best gameplay quality, please use ");
    printf("\033[37;7mmake asset\033[0m before launching the game.\n\n");
    printf("CONTROLS\n\n");
    printf("Use \033[37;7mZQSD\033[0m to move in each direction\n");
    printf("Use \033[37;7m^<v>\033[0m to look around\n");
    printf("Use \033[37;7mLShift\033[0m to sprint\n");
    printf("Use the \033[37;7mLeftMouseButton\033[0m to fire your weapon\n");
    printf("Use \033[37;7mE\033[0m to open your inventory\n");
    printf("Use \033[37;7mEsc\033[0m to open the menu while in game\n");
}

static void print_rules(void)
{
    printf("\n\n\t\tWelcome to \033[33;1mD.E.P.O.T.\033[0m !\n\n");
    printf("You are here to make us some \033[0;32mmoney\033[0m !\n");
    printf("To do so, you must collect some items in a lot of very nice ");
    printf("places.\nYou can find them everywhere so make sure you're ");
    printf("looking in every room !\nYou may encounter some ... Let's say ");
    printf("\033[0;31mcreatures\033[0m.\nYou can try to make friends with ");
    printf("them, but we wouldn't advise it.\nJust make sure you have ");
    printf("\033[36;4menough money\033[0m at the end, or we won't come for ");
    printf("you.\n\nBut most importantly, remember to ");
    printf("\033[0;35m✦★have some fun★✦\033[0m :)\n\n\n");
    print_controls();
}

static void print_character_lower_half(void)
{
    printf("''',,,,,,,:co:::::cc::lollloolllllccc:::::,,,,,:,,,,,''''......\n");
    printf(",,,,,,,,::doxl:,:,:::cccccccccc:cc::::::::,,,,,,,,,,,,,'''''''.\n");
    printf(",,,,:::,:xkdldoc::,:,:::::cccccc:::::,,,,,,,,,,.,,,,,,,,,''''''\n");
    printf(",:::::::cdkdoddolc::::cccccccccc::::::,,,,,,,l::,'c,,,,,,,'''''\n");
    printf(":::::::ccoxddoocloodkkkxdoolllccccc:::cccccccc',',:d,,,,,''''''\n");
    printf(":::::::::oddddddc:,::ccclxxxk0Okxddddl:,,,,,,,,llllll,,,'''''''\n");
    printf(":::::::::lodooool:',,:::::::::::::::::,,,,,,,'cccclcl,,,'''''''\n");
    printf("::::::::ccldooool:,,,,,,:,,::,:,,,:,,',,,,,,,cccllcccl,,'''''..\n");
    printf(":::::::::ccoolllc,:,,,,,,,,,,,,,,:,,,,,,,,'''cccclccc:c''''....\n");
    printf(":::::::::::lllll:,,,,,,,,,,,,,,,,,,,,,,,''''',c:cllccc:,.......\n");
    printf("::::::::::,:llcc:,,,,,,,,,,,,,,,,,,,,,,'''''.',:cccccc::'......\n");
    printf(",,,,,,,,,'',c::,',,,,,,,,,,,,:,,,,,,,'''''''.'.':ccccc:,,,.....\n");
    printf(",,,,,,,,,.',,,,,',,::::::::,,,',,,,''.....'.''..,:::cc::,,,,...\n");
    printf(",,,,''','.,','.'',,,:::::,,,,,'''''''............,:::::,,,','''\n");
    printf("''.'..'''''.''..''',:',c,',,''l'.''...............,,,,,,,''.'''\n");
    printf(",,,,,,,,,,,,,,,,,,,',',,,,,,,,,,,,,,,,,,,'',,,,,'',,,,,,,,,,,,,\n");
    print_rules();
}

int flag_h(void)
{
    printf(",,,,,,,,,,,,,,,,,,,,,',',,',,,,,,,,,',,,,,,,,,,,,,,,,,,,,,,,,,,\n");
    printf("....................,looooooooooollllllc'......................\n");
    printf("..............'..':dddddddxdddddooolllccccc....................\n");
    printf("..............,,lddddxxxkkkkkkxxxdoolllccccc:..................\n");
    printf("''.'..........,odooddxkkOOOOOkkxxdoollcccc::cc.................\n");
    printf("'''''.......,,xollllodxkOOOOOOkxxdollccoddolclc................\n");
    printf(",,,''''...':oO00000OkdoxkOOOOOkxxollkO000OOOkkxo,..............\n");
    printf("''''''...,oO00KXNXK0OkxloxkOkkkxolxOO0KNKK0Okkkxdl.............\n");
    printf("''''''..'oxOOO00000OkkxoldxkkkxdodkOOO000OOOkkxddoc............\n");
    printf("'''''''.,odxxkkkdcc:ddolcldxxkxdlodxxkdccclOkxdoolc'...........\n");
    printf("...''...,loodddo:,,',olccldxxxxolloodd,,,,,ldoolc::'...........\n");
    printf("'''''''..:ccllllc..':::::lddxxxdlcclll,...,llcc:::,............\n");
    printf("....'''''',:::::::::::,:cldddxxdll,::::::::::::,,,'..''........\n");
    printf("....''',,,,',,:,,,:,,,,:cloodxdxocc,,,,,,,,::,:,,..............\n");
    printf("...'',,,,,,o:,,,,,,,,::cllooddddooc:,:,,,,,,,,,,:......''''''''\n");
    printf("...'',,,,,,,k:ccccc:cc:lllooddddddlc::,,,,,,,,::,..............\n");
    printf("...'.,,',,,lxxkkOOOkxdocccc::ccc:::,,,,,,::loxdd'..............\n");
    printf("..'.''',',,ccccc:ldkOKKKKXKKKKK00Okxxxddooollc,,,'.............\n");
    print_character_lower_half();
    return EXIT_SUCCESS;
}
