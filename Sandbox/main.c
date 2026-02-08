int global_data_variable = 14;
int global_bss_variable;

int main(void)
{
    static int local_data_variable = 15;
    static int local_bss_variable; 

    while(1);

    return 0;
}
