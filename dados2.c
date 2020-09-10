#include <stdio.h>
#include <string.h>

struct endereco {
    char rua[50];
    unsigned int numero;
    char estado[50];
};

struct cadastro {
    char nome[50];
    unsigned int idade;
    float salario;
    struct endereco endr;
};

int main(void)
{
    struct cadastro cad[5];
    char str[50];
    int num = 0;
    int flag = 0;
    
    while (!flag)
    {
        char input[9];
        fgets(input, sizeof(input), stdin);
        input[strlen(input)-1] = '\0';
        
        if (!strcmp(input, "inserir"))
        {          
            if (num != 4)
            {
                scanf("%s %d %f %s %d %s", &cad[num].nome[0], &cad[num].idade, &cad[num].salario, 
                &cad[num].endr.rua[0], &cad[num].endr.numero, &cad[num].endr.estado[0]);
                printf("Registro %s %d %.2f %s %d %s inserido\n", cad[num].nome, cad[num].idade, 
                cad[num].salario, cad[num].endr.rua, cad[num].endr.numero, cad[num].endr.estado);
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
                    printf("Registro %s %d %.2f %s %d %s\n", cad[i].nome, cad[i].idade, cad[i].salario,
                    cad[i].endr.rua, cad[i].endr.numero, cad[i].endr.estado);
                    check++;
                    break;
                }
            }
            if (!check)
                printf("Registro ausente\n");
        }
        else if (!strcmp(input, "alterar"))
        {
            int check = 0;
            scanf("%s %d %f %s %d %s", &cad[4].nome[0], &cad[4].idade, &cad[4].salario, 
            &cad[4].endr.rua[0], &cad[4].endr.numero, &cad[4].endr.estado[0]);
            
            for (int i = 0; i < num; i++)
            {
                if (!strcmp(cad[i].nome, cad[4].nome))
                {
                    cad[i] = cad[4];
                    check++;
                    break;
                }
            }
            if (check) {
                printf("Registro %s %d %.2f %s %d %s alterado\n", cad[4].nome, cad[4].idade, cad[4].salario, 
                cad[4].endr.rua, cad[4].endr.numero, cad[4].endr.estado);
            }
            else
                printf("Registro ausente\n");
        }
        else
            flag++;
    }
    return 0;
}
