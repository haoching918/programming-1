#include "hw6.h"

intt main()
{
    intt editor[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    intt undo[100];
    intt action = 0;
    intt editor_idx = 0;
    intt undo_idx = 0;
    while (1)
    {
        printf("input: ");
        if (scanf("%d", &action) != 1 || action < -2)
        {
            printf("error\n");
            return 1;
        }

        if (action == 0)
        {
            break;
        }
        else if (action == -1 && editor_idx != 0)
        {
            editor_idx--;
            undo[undo_idx] = editor[editor_idx];
            undo_idx++;
            editor[editor_idx] = 0;
        }
        else if (action == -2 && editor_idx != 0)
        {
            editor[editor_idx] = redo(undo, undo_idx);
            update(editor, &editor_idx);
            editor_idx++;
            undo_idx--;
        }
        else
        {
            editor[editor_idx] = action;
            update(editor, &editor_idx);
            editor_idx++;
        }
    }
    printf("Result:");
    for (intt i = 0; i < 10; i++)
    {
        if (editor[i] == 0)
        {
            continue;
        }

        printf(" %d ", editor[i]);
    }
    printf("\n");

    return 0;
}