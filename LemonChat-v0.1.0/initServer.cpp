#include<iostream>
int main()
{
    system("md data");
    system("md data\\records");
    system("echo 0 > data\\records\\#");
    system("md data\\users");
    return 0;
}
