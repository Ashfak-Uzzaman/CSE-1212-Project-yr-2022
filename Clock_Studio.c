#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct time
{
    int h, m, s, c;
    int d, mo, y;
    char a[3];

} st, tmr;
//////////LEAP YEAR/////////////
int ly(int year)
{
    if (year % 400 == 0)
    {
        return 1;
    }
    else
    {
        if (year % 4 == 0 && year % 100 != 0)
        {
            return 1;
        }

        else
        {
            return 0;
        }
    }
}
//////////LEAP YEAR END/////////////

/////////  CLOCK  /////////////
void clock()
{

    struct time clk;
    int z = 1;
    while (z)
    {
        system("cls");
        printf("\t\t\tPlease Set Date (dd mm yyyy) : ");
        scanf("%d %d %d", &clk.d, &clk.mo, &clk.y);
        if (clk.d < 1 || (clk.mo > 12 || clk.mo < 1) || (clk.mo == 2 && ly(clk.y) == 1 && clk.d > 29) || (clk.mo == 2 && ly(clk.y) == 0 && clk.d > 28) || ((clk.mo == 9 || clk.mo == 4 || clk.mo == 6 || clk.mo == 11) && clk.d > 30) || (!(clk.mo == 9 || clk.mo == 4 || clk.mo == 6 || clk.mo == 11) && clk.d > 31))
        {
            z = 1;
            printf("\n\t\t\tInvalid Date!!! Please Enter Again.\n");
            sleep(2);
            system("cls");
        }
        else
        {
            z = 0;
        }
    }
    z = 1;
    while (z)
    {

        printf("\n\t\t\tPlease Set time (hh mm ss) : ");
        scanf("%d %d %d", &clk.h, &clk.m, &clk.s);
        if (clk.s > 59 || clk.m > 59 || clk.h > 23 || clk.s < 0 || clk.m < 0 || clk.h < 0)
        {
            z = 1;
            printf("\n\t\t\tInvalid Time!!! Please Enter Again.\n");
            sleep(1);
            system("cls");
        }
        else
        {
            z = 0;
        }
    }
    while (!_kbhit())
    {

        if (clk.s == 60)
        {
            clk.s = 0;
            clk.m++;
        }
        if (clk.m == 60)
        {
            clk.m = 0;
            clk.h++;
        }
        if (clk.h == 24)
        {
            clk.h = 0;

            if (clk.mo == 2 && ly(clk.y) == 1 && clk.d == 28)
            {
                clk.d++;
            }
            else if (clk.mo == 2 && (clk.d == 28 || clk.d == 29))
            {
                clk.d = 1;
            }

            else if (!(clk.mo == 9 || clk.mo == 4 || clk.mo == 6 || clk.mo == 11) && clk.d == 30)
            {
                clk.d++;
            }

            else if (clk.d == 30 || clk.d == 31)
            {
                clk.d = 1;
            }
            else
            {
                clk.d++;
            }

            if (clk.d == 1)
            {
                clk.mo++;
            }
            if (clk.mo == 13)
            {
                clk.mo = 1;
            }
            if (clk.mo == 1 && clk.d == 1)
            {
                clk.y++;
            }
        }

        sleep(1);

        system("cls");

        printf("\t\t\t\t\t%cDigital Clock%c\n\n", 4, 4);

        printf("\t\t\t\t\t--------------\n");
        printf("\t\t\t\t\t|%.2d : %.2d : %.2d|\n", clk.h, clk.m, clk.s);
        printf("\t\t\t\t\t--------------\n\n");
        printf("\t\t\t\t\t    Date\n", 4, 4);
        printf("\t\t\t\t\t--------------\n");
        printf("\t\t\t\t        %.2d - %.2d - %d\n", clk.d, clk.mo, clk.y);
        printf("\t\t\t\t\t--------------\n");
        printf("\n\t\t\t\t    Press Anykey to Go Back");
        clk.s++;
    }
}
/////////////// CLOCK END  ////////////////////

///////////////// STOP WATCH//////////////////////
void stwup()
{
    while (!_kbhit())
    {
        system("cls");
        printf("\n\n\t\t\t\t\t\t%.2d : %.2d : %.2d\n\n", st.h, st.m, st.s);
        printf("\t\t\t\t\t    Press Any Key to Stop\n");
        sleep(1);

        st.s++;
        if (st.s == 60)
        {
            st.s = 0;
            st.m++;
        }
        if (st.m == 60)
        {
            st.m = 0;
            st.h++;
        }
    }
    getch();
    system("cls");
    printf("\n\n\t\t\t\t\t\t%.2d : %.2d : %.2d\n\n", st.h, st.m, --st.s);
    printf("\t\t\t\t1. Start\t2. Reset & Start\t3. End\n");
}

int stwf()
{
    system("cls");
    printf("\n\n\t\t\t\t\t\t%.2d : %.2d : %.2d\n\n", st.h, st.m, st.s);
    printf("\t\t\t\t1. Start\t2. Reset & Start\t3. End\n");
    switch (getch())
    {
    case '1':
        stwup();
        break;

    case '2':
        st.h = st.m = st.s = 0;
        stwup();
        break;

    case '3':
        return 0;
    }
    return 1;
}

void stw()
{
    st.h = st.m = st.s = 0, st.c = 0;
    while (stwf())
    {
    }
}
///////////////// STOP WATCH END  //////////////////////

///////////////   TIMER  ///////////////////////

void timerf()
{
    if (tmr.m > 59 || tmr.s > 59)
    {
        system("cls");
        printf("\n\t\t\t\t\tInvalid Time!!!");

        printf("\n\n\t\t\t\t    Press any key to continue\n\n\n");
    }

    while ((!_kbhit()) && (tmr.s < 60 && tmr.m < 60))

    {
        system("cls");
        printf("\n\n\t\t\t\t\t\t%.2d : %.2d : %.2d\n", tmr.h, tmr.m, tmr.s);
        printf("\n\t\t\t\t\t  Press any key to stop\n");
        if (tmr.h == 0 && tmr.m == 0 && tmr.s == 0)
        {
            system("cls");
            printf("\n\n\t\t\t\t\t\t%.2d : %.2d : %.2d\n", tmr.h, tmr.m, tmr.s);
            printf("\n\t\t\t\t\tTimes up!! Timer has stopped.\n");
            sleep(3);
            system("cls");
            printf("\n\n\t\t\t\t\t\tPress any key\n");

            return;
        }
        if (tmr.s != 0)
        {
            tmr.s--;
        }
        if (tmr.m != 0 && tmr.s == 0)
        {
            tmr.s = 59;
            tmr.m--;
        }

        if (tmr.h != 0 && tmr.m == 0 && tmr.s == 0)
        {
            tmr.h--;
            tmr.m = 59;
            tmr.s = 59;
        }

        sleep(1);
    }

    return;
}

void timer()
{

    system("cls");

    printf("\n\t\t\t\tPlease set timer (hh mm ss) :");
    scanf("%d %d %d", &tmr.h, &tmr.m, &tmr.s);
    system("cls");
    timerf();

    while (1)
    {
        char a;
        getch();
        system("cls");
        if ((tmr.h == 0 && tmr.m == 0 && tmr.s == 0))
        {
            printf("\n\n\t\t\t\t1. Set Time & Start\t2. End\n");
            a = getch();
            a = a + 1;
        }
        else if (tmr.m > 59 || tmr.s > 59)
        {
            printf("Invalid Time!!!\n\n\n");
            system("cls");
            printf("\n\n\t\t\t\t1. Set Time & Start\t2. End\n");
            a = getch();
            a = a + 1;
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t%.2d : %.2d : %.2d\n\n", tmr.h, tmr.m, tmr.s);
            printf("\t\t\t\t1. Start\t2. Set Time & Start\t3. End\n");
            a = getch();
        }

        switch (a)
        {
        case '1':
            timerf();
            break;

        case '2':
            system("cls");

            printf("\n\t\t\t\t\tPlease set timer (hh mm ss) :");
            scanf("%d %d %d", &tmr.h, &tmr.m, &tmr.s);
            timerf();
            break; // st.h,st.m,st.s

        case '3':
            return;
        }
    }
}
///////////////  TIMER END /////////////////////

/////// POMODORO ///////////////
void pomodoro()
{
    struct time t;
    int i = 0;
    while ((!_kbhit()) && i < 4)
    {
        t.m = 25, t.s = 0;
        while (!_kbhit())
        {
            system("cls");
            printf("\t\t\t\t\t\tPOMODORO- %d\n\n", i + 1);
            printf("\t\t\t\t\t\t %.2d : %.2d\n", t.m, t.s);
            printf("\n\t\t\t\t\tPress Anykey to Dismiss\n\n\n");
            if (t.m == 0 && t.s == 0)
            {
                system("cls");
                break;
            }
            if (t.s != 0)
            {
                t.s--;
            }
            if (t.m != 0 && t.s == 0)
            {
                t.s = 59;
                t.m--;
            }
            sleep(1); /************************/
        }

        t.m = 5, t.s = 0;
        while (!_kbhit() && i < 3)
        {
            system("cls");
            printf("\t\t\t\t\t\tShort Break- %d\n\n", i + 1);
            printf("\t\t\t\t\t\t   %.2d : %.2d\n", t.m, t.s);
            printf("\n\t\t\t\t\tPress Anykey to Dismiss\n\n\n");

            if (t.m == 0 && t.s == 0)
            {
                system("cls");
                break;
            }
            if (t.s != 0)
            {
                t.s--;
            }
            if (t.m != 0 && t.s == 0)
            {
                t.s = 59;
                t.m--;
            }
        }
        i++;
    }
    if (i == 4)
    {
        printf("\t\t\t\t\t\t Well Done!!!\n\t\t\t\t\t\tPress any key.\n");
        getch();
        system("cls");
        printf("\t\t\t\t\tTake a Break and Come Back Again.\n\t\t\t\t\t\tNever Give Up");
    }
}
/////// POMODORO END /////////////

/////////First Day//////////////////
int firstday(int y)
{
    int day = (y * 365 + ((y - 1) / 4) - ((y - 1) / 100) + ((y - 1) / 400)) % 7;
    return day;
}
////////First Day End////////////

////////////Calender////////////////////
void calender()
{
    int z;
    while (1)
    {
        char mon[][15] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        int days_in_mon[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year;
        system("cls");
        printf("\t\t\tEnter Year: ");
        scanf("%d", &year);
        system("cls");
        printf("\n\n**************  Welcome to Year %d  ***************\n\n\n", year);
        int weekday = firstday(year);
        if (ly(year) == 1)
        {
            days_in_mon[1] = 29;
        }
        for (int i = 0; i < 12; i++)
        {
            printf("\n\n\n----------------------%s-------------------------\n", mon[i]);
            printf("\n    Sun    Mon    Tue    Wed    Thu    Fri    Sat\n");
            for (int k = 0; k < weekday; k++)
            {
                printf("       ");
            }
            for (int j = 1; j <= days_in_mon[i]; j++)
            {
                if (weekday == 7)
                {
                    weekday = 0;
                    printf("\n");
                }
                printf("%7d", j);
                weekday++;
            }
        }

        printf("\n\n\nDo You Want to continue? \n1. Yes\n2. No\n\n");
        scanf("%d", &z);
        if (z == 2)
        {
            break;
        }
    }
}

////////////Calender End////////////////////

int main()
{
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t***************************");
    printf("\n\t\t\t\t\t***************************");
    printf("\n\t\t\t\t\t%c WELCOME TO CLOCK STUDIO %c", 4, 4);
    printf("\n\t\t\t\t\t***************************");
    printf("\n\t\t\t\t\t***************************\n\n\n\n\n\n\n");

    sleep(2);
    system("cls");
    int z = 1;
    while (z)
    {
        printf("\t\t\t\t\t  %c Clock Studio \%c\n\n", 4, 4);
        printf("\t\t\t\t\t1. Digital Date & Clock\n\t\t\t\t\t2. Stopwatch\n");
        printf("\t\t\t\t\t3. Timer\n\t\t\t\t\t4. Pomodoro Timer\n\t\t\t\t\t5. Calender\n\t\t\t\t\t6. End\n\t\t\t\t\t\n\n");
        printf("\t\t\t\t\tPlease Choose Any Feature: ");
        char f;
        scanf("%c", &f);

        switch (f)
        {
        case '1':
            clock();
            break;
        case '2':
            stw();
            break;
        case '3':
            timer();
            break;
        case '4':
            pomodoro();
            break;
        case '5':
            calender();
            break;
        case '6':
            system("cls");
            printf("\n\n\n\n\t\t\t\t\tThanks for using our apps. See you soon\n\n\t\t\t\t\tClock Studion\n\t\t\t\t\tAuthor: Ashfak Uzzaman\n\n\n");
            sleep(1);
            system("cls");
            return 0;
        }

        system("cls");
    }
    return 0;
}
