#include"hw6.h"
#include"test.h"

intt main()
{
    checkCard(player1);
    checkCard(player2);
    checkCard(player3);
    checkCard(player4);
    printf( "Before:\n" );
    print_card( player1 );
    print_card( player2 );
    print_card( player3 );
    print_card( player4 );
    printf( "Type 01:\n" );
    sort_card( player1 , func01 );
    sort_card( player2 , func01 );
    sort_card( player3 , func01 );
    sort_card( player4 , func01 );
    print_card( player1 );
    print_card( player2 );
    print_card( player3 );
    print_card( player4 );
    printf( "Type 02:\n" );
    sort_card( player1 , func02 );
    sort_card( player2 , func02 );
    sort_card( player3 , func02 );
    sort_card( player4 , func02 );
    print_card( player1 );
    print_card( player2 );
    print_card( player3 );
    print_card( player4 );
    printf( "Type 03:\n" );
    sort_card( player1 , func03 );
    sort_card( player2 , func03 );
    sort_card( player3 , func03 );
    sort_card( player4 , func03 );
    print_card( player1 );
    print_card( player2 );
    print_card( player3 );
    print_card( player4 );
    return 0;
}