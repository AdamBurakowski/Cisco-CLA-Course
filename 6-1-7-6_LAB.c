/*
It is first functional version of this program.
I'm well aware that it is not very readable,
and could be written more efficiently.

But it seems to get the work done.
*/
#include <stdio.h>
#include <string.h>


void printString(char *str);
int octcheck(char *ip);
int chareval(char *ip);
int strint(char *str);
void ipeval(char *ip);


int main()
{
	ipeval("127.0.0.1");
	ipeval("127.0.01");
	ipeval("127.0..1");
	ipeval("127.zero.0.1");
	ipeval("127.297.0.1");
	ipeval("127.2555.0.1");
	
	return 0;
}

int strint(char *str)
{
    int result = 0;
    
    while(*str == ' ' || *str =='\t')
    {
        str++;
    }
    
    while(*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}

int chareval(char *ip)
{
    int valid = 0;
    
    char valchar[] = {'.', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    while(*ip != '\0')
    {
        for(int i = 0; i < 12; i++)
        {
            if(*ip == valchar[i])
            {
                valid = 1;
                break;
            }
            else
            {
                valid = 0;
            }
        }
        if(valid == 0)
            {
                break;
            }
        ip++;
    }
    
    return valid;
}

int octcheck(char *ip)
{
    int dots = 0;
    int valid = 0;
    int num = 0;
    int len[4] = {0};
    char *start = ip;
    while(*ip != '\0')
    {
        if(*ip == '.')
        {
            if(num > 0 && num <= 3)
            {
                valid = 1;
                len[dots] = ip - start;
            }
            else
            {
                valid = 0;
                break;
            }
            dots++;
            num = 0;
            start = ip + 1;
        }
        else
        {
            num++;
        }
        ip++;
    }
    
    if (num > 0 && num <= 3)
    {
        valid = 1;
        len[dots] = ip - start;
        len[dots] = num;
    }
    else
    {
        valid = 0;
    }
    
    if(valid && dots == 3)
    {
        valid = 1;
    }
    else
    {
        valid = 0;
    }
    
    ip -= (len[0] + len[1] + len[2] + len[3]);
    
    for(int i = 0; i < 4; i++)
    {
        char octet[4];
        strncpy(octet, ip - len[i], len[i]);
        octet[len[i]] = '\0';
        int value = strint(octet);
        if(value > 255)
        {
            valid = 0;
            break;
        }
        ip += len[i] + 1;
    }
    return valid;
}

void ipeval(char *ip)
{
    int valid = octcheck(ip);
	if(valid)
    {
        valid = chareval(ip);
        if(valid)
        {
            printf("%s is a valid IP address\n", ip);
        }
        else
        {
            printf("%s is not a valid IP address\n", ip);
        }
    }
    else
    {
        printf("%s is not a valid IP address\n", ip);
    }
}
