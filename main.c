#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dato
{
    char regione[31], area;
    int mese;
};
int main(int argc, char *argv[])
{
    struct dato s;
    FILE *fp;
    int cont=0;
    char regione_file[20][31];
    int num_ing[20]={0}, num_arc[20]={0};
    char riga[1000];
    int flag_trovato = 0;
    int mese[6], cont_mese[6]={0};
    int quanti_mesi=0, flag_mese=0;
    char mese_stringhe [6][30];
    int numero[20];
    int i, max=0, min;
    int pos_max, pos_min;


    if (argc!=2)
    {
        printf("usage: ./main path\n");
        exit(-1);
    }
    fp = fopen(argv[1], "r");
    if (fp== NULL)
    {
        printf("Errore file!");
        exit(-1);
    }
    while (!feof(fp))
    {
        fgets(riga, 1000, fp);
        sscanf(riga, "%*s %*s %s %*2d/%2d/%*4d %c", s.regione, &s.mese, &s.area);
        if (cont == 0)
        {
            cont++;
            strcpy(regione_file[0], s.regione);
            if (s.area == 'A')
                num_arc[0]++;
            if (s.area == 'I')
                num_ing[0]++;
            mese[0]=s.mese;
            cont_mese[0]++;
            quanti_mesi++;
        }
        else
        {
            for (i=0; i<cont && flag_trovato == 0; i++)
            {
                if (strcmp(regione_file[i], s.regione)==0)
                {
                    flag_trovato=1;
                    if (s.area == 'A')
                        num_arc[i]++;
                    if (s.area == 'I')
                        num_ing[i]++;
                }
            }
            if (flag_trovato == 0)
            {
                strcpy(regione_file[cont], s.regione);
                if (s.area == 'A')
                        num_arc[cont]++;
                if (s.area == 'I')
                        num_ing[cont]++;
                cont++;
            }
            flag_trovato=0;
            for (i=0; i<quanti_mesi && flag_mese==0; i++)
            {
                if (mese[i] == s.mese)
                {
                    flag_mese=1;
                    cont_mese[i]++;
                }
            }
            if (flag_mese==0)
            {
                mese[quanti_mesi] = s.mese;
                cont_mese[quanti_mesi]++;
                quanti_mesi++;
            }
            flag_mese=0;
        }

    }

    for (i=0; i<quanti_mesi; i++)
    {
        switch (mese[i])
        {
        case 4:
            strcpy(mese_stringhe[i], "Aprile");
            break;
        case 5:
            strcpy(mese_stringhe[i], "Maggio");
            break;
        case 6:
            strcpy(mese_stringhe[i], "Giugno");
            break;
        case 7:
            strcpy(mese_stringhe[i], "Luglio");
            break;
        case 8:
            strcpy(mese_stringhe[i], "Agosto");
            break;
        case 9:
            strcpy(mese_stringhe[i], "Settembre");
            break;
        }
    }
    for (i=0; i<cont; i++)
    {
        numero[i] = num_arc[i] + num_ing[i];
    }
    min = numero[0];
    for (i=0; i<cont; i++)
    {
        if (numero[i] > max)
        {
            max = numero[i];
            pos_max = i;
        }
        if (numero[i] < min)
        {
            min = numero[i];
            pos_min = i;
        }
    }
    printf("%-20s %-30s %s\n", "Regione", "N.Studenti Ingegneria", "N.Studenti Architettura");
    for (i=0; i<cont;i++)
    {
        printf("%-20s %-30d %d\n", regione_file[i], num_ing[i], num_arc[i]);
    }
    printf("%-20s %s\n", "Mese", "N.Studenti Immatricolati in totale");
    for (i=0; i<cont; i++)
    {
     printf("%-20s %d\n", mese_stringhe[i], cont_mese[i]);
    }
    printf("Max studenti è %s\n", regione_file[pos_max]);
    printf("Min studenti è %s\n", regione_file[pos_min]);
    return 0;
}
