#include <stdio.h>
#include <string.h>

struct cadastro {
    char nome[50];
    unsigned int idade;
    float salario;
};

int main(void)
{
    struct cadastro cad[4];
    char str[50];
    int num = 0;
    int flag = 0;

    while(!flag)
    {
        char input[9];
        fgets(input, sizeof(input), stdin);
        input[strlen(input)-1] = '\0';
            
        if (!strcmp(input, "inserir"))
        {          
            if (num != 4)
            {
                scanf("%s %d %f", &cad[num].nome[0], &cad[num].idade, &cad[num].salario);
                printf("Registro %s %d %.2f inserido\n", cad[num].nome, cad[num].idade, cad[num].salario);
                num++;
            }
            else
                printf("Espaco isnuficiente\n");
        }
        else if (!strcmp(input, "mostrar"))
        {
            char nome[50];
            int check = 0;
            fgets(nome, sizeof(nome), stdin);
            nome[strlen(nome)-1] = '\0';
            
            for (int i = 0; i < num; i++)
            {
                if (!strcmp(nome, cad[i].nome))
                {
                    printf("Registro %s %d %.2f\n", cad[i].nome, cad[i].idade, cad[i].salario);
                    check++;
                    break;
                }
            }
            if (check == 0)
                printf("Registro ausente\n");
        }
        else
            flag++;
    }
    return 0;
}
