#include <stdio.h>
#include <stdbool.h>

// bool match(char* wzorzec, char* lancuch)
// {
//     switch (*wzorzec)
//     {
//         case '\0':
//             return (*lancuch == '\0' ? true : false);
//         break;
        
//         case '?':
//             if(*lancuch == '\0')
//             {
//                 return false;
//             }
//             return match(wzorzec + 1, lancuch + 1);
//         break;

//         case '*':
//             if(*(wzorzec + 1) == '\0')
//             {
//                 return true;
//             }

//             int i = 1;
//             while(*(lancuch + i - 1) != '\0')
//             {
//                 if(*(wzorzec + i) == '*')
//                 {
//                     return match(wzorzec + i, lancuch + i - 1);
//                 }
//                 else if( *(wzorzec + i) == '?' || *(wzorzec + i) == *(lancuch + i - 1))
//                 {
//                     i++;
//                 }
//                 else
//                 {
//                     return match(wzorzec, lancuch + i); 
//                 }
//             }
//             if(*(wzorzec + i) == '\0')
//             {
//                 return true;
//             }
//             return false;
//         break;

//         default:
//             if(*lancuch == '\0' || *wzorzec != *lancuch)
//             {
//                 return false;
//             }

//             return match(wzorzec + 1, lancuch + 1);
//         break;
//     }
// }

bool match(char* wzorzec, char* lancuch)
{
    while(*wzorzec != '\0')
    {
        if(*lancuch == '\0')
        {
            return false;
        }
        else if(*wzorzec == '?' || *wzorzec == *lancuch)
        {
            wzorzec++;
            lancuch++;
        }
        else if (*wzorzec == '*')
        {
            if(*(wzorzec + 1) == '\0')
            {
                return true;
            }

            int i = 1;
            while(true)
            {
                if(*(lancuch + i - 1) == '\0' && *(wzorzec + i) == '\0')
                {
                    return true;
                }
                if(*(wzorzec + i) == '*')
                {
                    wzorzec += i;
                    lancuch += i - 1;
                    break;
                }
                else if(*(wzorzec + i) == '?' || *(wzorzec + i) == *(lancuch + i - 1))
                {
                    i++;
                }
                else
                {
                    lancuch++;
                    break; 
                }
            }
        }
        else
        {
            return false;
        }

    }

    return (*lancuch == '\0' ? true : false); 
}

int main()
{
    char wzorzec[100], lancuch[100];
    printf("wzorzec: ");
    scanf("%s", wzorzec);
    printf("lancuch: ");
    scanf("%s", lancuch);
    
    printf(match(wzorzec, lancuch) ? "true\n" : "false\n");
}