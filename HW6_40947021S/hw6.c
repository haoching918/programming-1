#include "hw6.h"

//hw0601
void byte_position(int64_t *ptr_integer)
{
    uint8_t *split = (uint8_t *)ptr_integer;
    for (intt i = 0; i < 8; i++)
    {
        printf("(%d) 0x%02X ", i + 1, *(split + i));
    }
    printf("\n");
}

void valueChage(int64_t *ptr_integer, intt position, intt change)
{
    uint8_t *split = (uint8_t *)ptr_integer;
    *(split + position - 1) = change;
}

//hw0602
intt redo(intt *undo, intt undo_idx)
{
    if (undo_idx - 1 >= 0)
    {
        return undo[undo_idx - 1];
    }
    else
    {
        return 0;
    }
}

void update(intt *editor, intt *editor_idx)
{
    if (*editor_idx > 9)
    {
        for (intt i = 0; i < 10; i++)
        {
            editor[i] = editor[i + 1];
        }
        (*editor_idx)--;
    }
}

//hw0603
void rotate(double *x, double *y, double theta)
{
    double radians = (theta * (-1) / 180) * M_PI;
    double rx = *x, ry = *y;
    *x = cos(radians) * rx + (-sin(radians)) * ry;
    *y = sin(radians) * rx + cos(radians) * ry;
}

//hw0604
void getPlane(intt a, intt b, intt c, intt d)
{
    if (a == 1)
    {
        printf("x");
    }
    else if (a == -1)
    {
        printf("-x");
    }
    else if (a != 0)
    {
        printf("%dx", a);
    }

    if (b > 0)
    {
        if (a == 0)
        {
            if (b == 1)
            {
                printf("y");
            }
            else
            {
                printf("%dy", b);
            }
        }
        else
        {
            if (b == 1)
            {
                printf("+y");
            }
            else
            {
                printf("+%dy", b);
            }
        }
    }
    else if (b < 0)
    {
        if (b == -1)
        {
            printf("-y");
        }
        else
        {
            printf("%dy", b);
        }
    }

    if (c > 0)
    {
        if (a == 0 && b == 0)
        {
            if (c == 1)
            {
                printf("z");
            }
            else
            {
                printf("%dz", c);
            }
        }
        else
        {
            if (c == 1)
            {
                printf("+z");
            }
            else
            {
                printf("+%dz", c);
            }
        }
    }
    else if (c < 0)
    {
        if (c == -1)
        {
            printf("-z");
        }
        else
        {
            printf("%dz", c);
        }
    }

    if (d > 0)
    {
        if (a == 0 && b == 0 && c == 0)
        {
            printf("%d", d);
        }
        else
        {
            printf("+%d", d);
        }
    }
    else if (d < 0)
    {
        printf("%d", d);
    }

    printf("=0\n");
}

void project(double *x, double *y, double *z, intt a, intt b, intt c, intt d)
{
    double t;
    t = (a * (*x) + b * (*y) + c * (*z) + d) / (a * a + b * b + c * c);
    double px = (*x) - a * t;
    double py = (*y) - b * t;
    double pz = (*z) - c * t;
    printf("The projection is (%lf,%lf,%lf)\n", px, py, pz);
}

//hw0605
void print_card(const uint8_t player[13])
{
    for (intt i = 0; i < 13; i++)
        printf(" %d ", player[i]);
    printf("\n");
}

void checkCard(uint8_t player[13])
{
    for (intt i = 0; i < 13; i++)
    {
        for (intt j = 0; j < 13; j++)
        {
            if (player[i] < 1 || player[i] > 52)
            {
                printf("wrong card\n");
                exit(1);
            }
            if (i == j)
            {
                continue;
            }
            if (player[i] == player[j])
            {
                printf("wrong card\n");
                exit(1);
            }
        }
    }
}

void sort_card(uint8_t player[13], intt (*compare)(intt a, intt b))
{
    for (intt i = 0; i < 13; i++)
    {
        for (intt j = i; j < 13; j++)
        {
            intt tmp = player[i];
            player[i] = compare(player[i], player[j]);
            if (player[i] != tmp)
            {
                player[j] = tmp;
            }
        }
    }
}

intt func01(intt a, intt b)
{
    intt numA = a % 13;
    intt numB = b % 13;
    if (numA == 1)
    {
        numA = 14;
    }
    else if (numA == 0)
    {
        numA = 13;
    }
    if (numB == 1)
    {
        numB = 14;
    }
    else if (numB == 0)
    {
        numB = 13;
    }

    if (numA > numB)
    {
        return a;
    }
    else
    {
        return b;
    }
}

intt func02(intt a, intt b)
{
    intt numA = a % 13;
    intt numB = b % 13;
    if (numA == 1)
    {
        numA = 14;
    }
    else if (numA == 0)
    {
        numA = 13;
    }
    else if (numA == 2)
    {
        numA = 15;
    }

    if (numB == 1)
    {
        numB = 14;
    }
    else if (numB == 0)
    {
        numB = 13;
    }
    else if (numB == 2)
    {
        numB = 15;
    }

    if (numA > numB)
    {
        return a;
    }
    else
    {
        return b;
    }
}

intt func03(intt a, intt b)
{
    intt suitA = suitDet(a);
    intt suitB = suitDet(b);

    if (suitA > suitB)
    {
        return a;
    }
    else if (suitA == suitB)
    {
        if (numDet(a) > numDet(b))
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    else
    {
        return b;
    }
}

intt suitDet(intt card)
{
    if (card <= 13)
    {
        return 4;
    }
    else if (card <= 26)
    {
        return 3;
    }
    else if (card <= 39)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

intt numDet(intt card)
{
    intt num = card % 13;
    if (num == 1)
    {
        num = 14;
    }
    else if (num == 0)
    {
        num = 13;
    }
    return num;
}