#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data
{
    char Nom[20];
    char Prenom[20];
    char CNE[15];
    float notes[4];
    float moyenne;
} data;

typedef struct node
{
    data infor;
    struct node * link;
} node;

void menu_0();
data Initialisation();
node * insert_at_end(node * head,data info);
node * insert_at_beg(node * head,data info);
void affichage(node * head);
void Etudiant(node *head);
void print_module(node * head,int i);
void Print(node * head,int i);
void Affichage_5_Premier_Etudiants(node * head,int i);
node * rechercheetudiant_par_Nom_Prenom(node * head,char * nom,char * prenom);
node * rechercheetudiant_par_CNE(node * head,char *S);
node * supprimeretudiant_par_CNE(node * head,char * S);
node * supprimeretudiant_par_Nom_Prenom(node * head,char * nom,char * prenom);
node * trie_par_moyenne(node*head,int ordre);
node * trie_par_CNE(node*head,int ordre);
node * trie_par_NOM(node*head,int ordre);
node * trie_par_Module(node*head,int k,int ordre);
int Nbr_etudiant_valider_Module(node * head,int i);
int Nbr_etudiant_Nonvalider_Module(node * head,int i);
int Nbr_etudiant_Rate(node * head,int i);
node * supprimerlist(node * head);
int main()
{
    menu_0();
    menu_2();
    return 0;
}

void menu_0()
{
    printf("\n\t\t==================================================================");
    printf("\n\t\t Bienvenue a ce programme qu\'est permet de manager les etudiants:");
    printf("\n\t\t==================================================================");
    printf("\n\n\t\t\tRealises par: Falak Youssef && Charaf-eddine Kaouri");
    printf("\n\n\t\t\t      De 17/03/23 A 19/03/23");
    printf("\n\t\t------------------------------------------------------");
    printf("\n\t\tCe programme est capable de vous donner la possibiliter:");
    printf("\n\n\t\t-D\'ajouter Des Etudiants.");
    printf("\n\n\t\t-Chercher Des Etudiants.");
    printf("\n\n\t\t-Supprimer Des Etudiants.");
    printf("\n\n\t\t-Trie Des Etudiants.");
    system("pause>1");
    system("cls");
}
int menu_1()
{
    int choice;
    printf("\n\n\t Veuillez choisir l'un de ces options suivantes: ");
    printf("\n\n\t\t\t1-Importer a partir d'une liste:");
    printf("\n\n\t\t\t2-Ajouter Un Etudiant:");
    printf("\n\n\t\t\t3-Affichage de la liste:");
    printf("\n\n\t\t\t4-Chercher Un Etudiant:");
    printf("\n\n\t\t\t5-Supprimer Un Etudiant:");
    printf("\n\n\t\t\t6-Trie Les Etudiants:");
    printf("\n\n\t\t\t7-Afficher Les Etudiants Valider:");
    printf("\n\n\t\t\t8-Afficher Les Etudiants NonValider:");
    printf("\n\n\t\t\t9-Afficher Les Etudiants Rate :");
    printf("\n\n\t\t\t10-Afficher Les Cinq Premiers Etudiants :");
    printf("\n\n\t\t\t11-Quitter Le Processus: ");
    printf("\n");
    printf("\n\tReponse:");
    scanf("%d",&choice);
    system("cls");
    return choice;
}
void menu_2()
{
    int choice,choice2,ordre;
    FILE* pf;
    data info;
    node * head=NULL;
    node * ptr=NULL;
    int Nbr;
    int flag=1;
    char S[20];
    char S1[20];
    do
    {
        int result=menu_1();
        switch(result)
        {
        case 1:
            pf=fopen("list_etudiant.txt","rt");
            if(pf==NULL)
            {
                printf("\n\n\tERREUR d'ouvrir le fichier");
                exit(33);
            }
            printf("\n\n\t 1-Insertion Au debut");
            printf("\n\t 2-Insertion A La Fin\n");
            printf("\n Reponse:");
            scanf("%d",&choice);
            system("cls");
            while(fscanf(pf,"%[^:]:%[^:]:%[^:]:%f:%f:%f:%f:%f%*[\n]",info.Nom,info.Prenom,info.CNE,&info.notes[0],&info.notes[1],&info.notes[2],&info.notes[3],&info.moyenne)==8)
            {
                if(choice==1)
                    head=insert_at_beg(head,info);
                else
                    head=insert_at_end(head,info);

            }
            printf("\n\n\tImportation de la liste reussie.");
            system("pause>1");
            system("cls");
            fclose(pf);
            pf=NULL;
            break;

        case 2:
            printf("\n\n\t 1-Insertion Au debut");
            printf("\n\t 2-Insertion A La Fin\n");
            printf("\n Reponse:");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                head=insert_at_beg(head,Initialisation());
            else
                head=insert_at_end(head,Initialisation());
            break;
        case 3:
            system("cls");
            printf("\n");
            affichage(head);
            system("pause>1");
            system("cls");
            break;
        case 4:
            if(head==NULL)
            {
                printf("\n\t\tList is empty.\n");
                system("pause>1");
                system("cls");
                break;
            }
            printf("\n\n\t 1-Chercher Par CNE\n");
            printf("\t 2-Chercher Par Nom et Prenom\n");
            printf("\n\tReponse:");
            scanf("%d",&choice);
            fflush(stdin);
            if(choice==1)
            {
                system("cls");
                printf("\n\n\t Entrer CNE a chercher:");
                gets(S);
                ptr=rechercheetudiant_par_CNE(head,S);
                if(ptr==NULL)
                    printf("\n\tL\'etudiant n\'existe pas dans la liste\n");
                else
                {
                    printf("\n\tL\'etudiant a trouve\n");
                    Etudiant(ptr);
                }
                system("pause>1");
                system("cls");
            }
            else
            {
                system("cls");
                printf("\n\n\t Veuillez Entrer Nom:");
                gets(S);
                printf("\t Veuillez Entrer Prenom:");
                gets(S1);
                ptr=rechercheetudiant_par_Nom_Prenom(head,S,S1);
                if(ptr==NULL)
                    printf("\n\tL\'etudiant n\'existe pas dans la liste\n");
                else
                {
                    printf("\n\tL\'etudiant a trouve\n");
                    Etudiant(ptr);
                }
                system("pause>1");
                system("cls");
            }
            break;
        case 5:
            if(head==NULL)
            {
                printf("\n\t\tList is empty.\n");
                system("pause>1");
                system("cls");
                break;
            }
            printf("\n\n\t 1-Supprimer Un Etudiant Par CNE\n");
            printf("\t 2-Supprimer Un Etudiant Par Nom et Prenom\n");
            printf("\n\tReponse:");
            scanf("%d",&choice);
            fflush(stdin);
            if(choice==1)
            {
                system("cls");
                if(head==NULL)
                {
                    printf("List is empty.\n");
                    break;
                }
                printf("\n\n\t Veuillez Entrer CNE :");
                gets(S);
                ptr=rechercheetudiant_par_CNE(head,S);
                if(ptr==NULL)
                {
                    printf("\n\tL\'etudiant n\'existe pas\n");
                    system("pause>1");
                    system("cls");
                }
                else
                {
                    head=supprimeretudiant_par_CNE(head,S);
                    printf("\tL\'etudiant est supprime\n");
                    system("pause>1");
                    system("cls");
                }
            }
            else
            {
                system("cls");
                if(head==NULL)
                {
                    printf("List is empty.\n");
                    break;
                }
                printf("\n\n\t Veuillez Entrer Nom:");
                gets(S);
                printf("\t Veuillez Entrer Prenom:");
                gets(S1);
                ptr=rechercheetudiant_par_Nom_Prenom(head,S,S1);
                if(ptr==NULL)
                {
                    printf("\n\tL\'etudiant n\'existe pas\n");
                    system("pause>1");
                    system("cls");
                }
                else
                {
                    head=supprimeretudiant_par_Nom_Prenom(head,S,S1);
                    printf("\n\tL\'etudiant est supprime\n");
                    system("pause>1");
                    system("cls");
                }
            }
            break;
        case 6:
            if(head==NULL)
            {
                printf("\n\tList is already empty.\n");
                system("pause>1");
                system("cls");
                break;
            }
            printf("\n\n\t\t\t1-Trie Les Etudiants Par Moyenne Generale:");
            printf("\n\n\t\t\t2-Trie Les Etudiants Par NOM:");
            printf("\n\n\t\t\t3-Trie Les Etudiants Par CNE:");
            printf("\n\n\t\t\t4-Trie Les Etudiants Par Note du Module :");
            printf("\n\tReponse:");
            do
            {
                scanf("%d",&choice);
            }
            while(choice<1||choice>4);
            if(choice==4)
            {
                system("cls");
                printf("\n\n\t 1-Module de Structure de Donnee et Devellopement Web\n");
                printf("\n\n\t 2-Module de Base de Donnee et Systeme D\'information\n");
                printf("\n\n\t 3-Module de Systeme D\'exploitation et Reseau\n");
                printf("\n\n\t 4-Module D\'analyse numerique et Statistique \n");
                printf("\n\tReponse:");
                do
                {
                    scanf("%d",&choice2);
                }
                while(choice2<1||choice2>4);
                system("cls");
                printf("\n\n\t 1-Ordre decroissante\n\n\t 2-Ordre croissante\n");
                do
                {
                    printf("\t Reponse:");
                    scanf("%d",&ordre);
                }
                while(ordre!=1&&ordre!=2);
                system("cls");
                head=trie_par_Module(head,choice2-1,ordre);
                printf("\n\n");
                print_module(head,choice2-1);
                system("pause>1");
                system("cls");
            }
            else if(choice==1)
            {
                system("cls");
                printf("\n\n\t 1-Ordre decroissante\n\n\t 2-Ordre croissante\n");
                do
                {
                    printf("\t Reponse:");
                    scanf("%d",&ordre);
                }
                while(ordre!=1&&ordre!=2);
                system("cls");
                head=trie_par_moyenne(head,ordre);
                printf("\n\n");
                affichage(head);
                system("pause>1");
                system("cls");
            }
            else if(choice==2)
            {
                system("cls");
                printf("\n\n\t 1-Ordre decroissante\n\n\t 2-Ordre croissante\n");
                do
                {
                    printf("\t Reponse:");
                    scanf("%d",&ordre);
                }
                while(ordre!=1&&ordre!=2);
                system("cls");
                head=trie_par_NOM(head,ordre);
                printf("\n\n");
                affichage(head);
                system("pause>1");
                system("cls");
            }
            else if(choice==3)
            {
                system("cls");
                printf("\n\n\t 1-Ordre decroissante\n\n\t 2-Ordre croissante\n");
                do
                {
                    printf("\t Reponse:");
                    scanf("%d",&ordre);
                }
                while(ordre!=1&&ordre!=2);
                system("cls");
                head=trie_par_CNE(head,ordre);
                printf("\n\n");
                affichage(head);
                system("pause>1");
                system("cls");
            }
            break;
        case 7:
             if(head==NULL)
            {
                printf("\n\tList is already empty.\n");
                system("pause>1");
                system("cls");
                break;
            }
            printf("\n\n\t 1-Module de Structure de Donnee et Devellopement Web\n");
            printf("\n\n\t 2-Module de Base de Donnee et Systeme D\'information\n");
            printf("\n\n\t 3-Module de Systeme D\'exploitation et Reseau\n");
            printf("\n\n\t 4-Module D\'analyse numerique et Statistique \n");
            printf("\n\tReponse:");
            scanf("%d",&choice);
            if(choice==1)
            {
                system("cls");
                printf("\n\tAffichage Des Etudiants Valide SD:\n");
                Nbr=Nbr_etudiant_valider_Module(head,0);
                printf("\n\n\tLe Nombre Des Etudiants Valide est:%d",Nbr);
                system("pause>1");
                system("cls");
            }
            else if(choice==2)
            {
                system("cls");
                printf("\n\tAffichage Des Etudiants Valide DB:\n");
                Nbr=Nbr_etudiant_valider_Module(head,1);
                printf("\n\n\tLe Nombre Des Etudiants Valide est:%d",Nbr);
                system("pause>1");
                system("cls");
            }
            else if(choice==3)
            {
                system("cls");
                printf("\n\tAffichage Des Etudiants Valide SE:\n");
                Nbr=Nbr_etudiant_valider_Module(head,2);
                printf("\n\n\tLe Nombre Des Etudiants Valide est:%d",Nbr);
                system("pause>1");
                system("cls");
            }
            else
            {
                system("cls");
                printf("\n\tAffichage Des Etudiants Valide AN:\n");
                Nbr=Nbr_etudiant_valider_Module(head,3);
                printf("\n\n\tLe Nombre Des Etudiants Valide est:%d",Nbr);
                system("pause>1");
                system("cls");
            }
            break;
        case 8:
             if(head==NULL)
            {
                printf("\n\tList is already empty.\n");
                system("pause>1");
                system("cls");
                break;
            }
            printf("\n\n\t 1-Module de Structure de Donnee et Devellopement Web\n");
            printf("\n\n\t 2-Module de Base de Donnee et Systeme D\'information\n");
            printf("\n\n\t 3-Module de Systeme D\'exploitation et Reseau\n");
            printf("\n\n\t 4-Module D\'analyse numerique et Statistique \n");
            printf("\n\tReponse:");
            scanf("%d",&choice);
            if(choice==1)
            {
                system("cls");
                printf("\n\tAffichage Des Etudiants Non Valide SD:\n");
                Nbr=Nbr_etudiant_Nonvalider_Module(head,0);
                printf("\n\n\tLe Nombre Des Etudiants Non Valide est :%d",Nbr);
                system("pause>1");
                system("cls");
            }
            else if(choice==2)
            {
                system("cls");
                printf("\n\tAffichage Des Etudiants Non Valide BD:\n");
                Nbr=Nbr_etudiant_Nonvalider_Module(head,1);
                printf("\n\n\tLe Nombre Des Etudiants Non Valide est :%d",Nbr);
                system("pause>1");
                system("cls");
            }
            else if(choice==3)
            {
                system("cls");
                printf("\n\tAffichage Des Etudiants Non Valide SE:\n");
                Nbr=Nbr_etudiant_Nonvalider_Module(head,2);
                printf("\n\n\tLe Nombre Des Etudiants Non Valide est :%d",Nbr);
                system("pause>1");
                system("cls");
            }
            else
            {
                system("cls");
                printf("\n\tAffichage Des Etudiants Non Valide AN:\n");
                Nbr=Nbr_etudiant_Nonvalider_Module(head,3);
                printf("\n\n\tLe Nombre Des Etudiants Non Valide est :%d",Nbr);
                system("pause>1");
                system("cls");
            }
            break;
        case 9:
             if(head==NULL)
            {
                printf("\n\tList is already empty.\n");
                system("pause>1");
                system("cls");
                break;
            }
            printf("\n\n\t 1-Module de Structure de Donnee et Devellopement Web\n");
            printf("\n\n\t 2-Module de Base de Donnee et Systeme D\'information\n");
            printf("\n\n\t 3-Module de Systeme D\'exploitation et Reseau\n");
            printf("\n\n\t 4-Module D\'analyse numerique et Statistique \n");
            printf("\n\tReponse:");
            scanf("%d",&choice);
            if(choice==1)
            {
                system("cls");
                printf("\n\tAffichage Des Etudiants Rate en SD:\n");
                Nbr=Nbr_etudiant_Rate(head,0);
                printf("\n\n\tLe Nombre Des Etudiants Rate est :%d",Nbr);
                system("pause>1");
                system("cls");
            }
            else if(choice==2)
            {
                system("cls");
                printf("\n\tAffichage Des Etudiants Rate en BD:\n");
                Nbr=Nbr_etudiant_Rate(head,1);
                printf("\n\n\tLe Nombre Des Etudiants Rate est :%d",Nbr);
                system("pause>1");
                system("cls");
            }
            else if(choice==3)
            {
                system("cls");
                printf("\n\tAffichage Des Etudiants Rate en SE:\n");
                Nbr=Nbr_etudiant_Rate(head,2);
                printf("\n\n\tLe Nombre Des Etudiants Rate est :%d",Nbr);
                system("pause>1");
                system("cls");
            }
            else
            {
                system("cls");
                printf("\n\tAffichage Des Etudiants Rate en AN:\n");
                Nbr=Nbr_etudiant_Rate(head,3);
                printf("\n\n\tLe Nombre Des Etudiants Rate est :%d",Nbr);
                system("pause>1");
                system("cls");
            }
            break;
        case 10:
             if(head==NULL)
            {
                printf("\n\tList is already empty.\n");
                system("pause>1");
                system("cls");
                break;
            }
            printf("\n\n\t 1-Module de Structure de Donnee et Devellopement Web\n");
            printf("\n\n\t 2-Module de Base de Donnee et Systeme D\'information\n");
            printf("\n\n\t 3-Module de Systeme D\'exploitation et Reseau\n");
            printf("\n\n\t 4-Module D\'analyse numerique et Statistique \n");
            printf("\n\tReponse:");
            scanf("%d",&choice);
            if(choice==1)
            {
                system("cls");
                printf("\n\n");
                Affichage_5_Premier_Etudiants(head,0);
                system("pause>1");
                system("cls");
            }
            else if(choice==2)
            {
                system("cls");
                printf("\n\n");
                Affichage_5_Premier_Etudiants(head,1);
                system("pause>1");
                system("cls");
            }
            else if(choice==3)
            {
                system("cls");
                printf("\n\n");
                Affichage_5_Premier_Etudiants(head,2);
                system("pause>1");
                system("cls");
            }
            else
            {
                system("cls");
                printf("\n\n");
                Affichage_5_Premier_Etudiants(head,3);
                system("pause>1");
                system("cls");
            }
            break;
        case 11:
            head=supprimerlist(head);
            exit(0);
        default:
            printf("\n\n\t\tInvalid Option Entered!\n");
            system("pause>1");
            system("cls");
        }
    }
    while(flag);
}
data Initialisation()
{
    data info;
    fflush(stdin);
    printf(" \n\tEntrer Nom:");
    gets(info.Nom);
    printf(" \tEntrer Prenom:");
    gets(info.Prenom);
    printf(" \tEntrer CNE:");
    gets(info.CNE);

    do
    {
        printf(" \tEntrer Note De SD:");
        scanf("%f",&info.notes[0]);
    }
    while(info.notes[0]<0||info.notes[0]>20);
    do
    {
        printf(" \tEntrer Note De BD:");
        scanf("%f",&info.notes[1]);
    }
    while(info.notes[1]<0||info.notes[1]>20);
    do
    {
        printf(" \tEntrer Note De SE:");
        scanf("%f",&info.notes[2]);
    }
    while(info.notes[2]<0||info.notes[2]>20);
    do
    {
        printf(" \tEntrer Note D\'AN:");
        scanf("%f",&info.notes[3]);
    }
    while(info.notes[3]<0||info.notes[3]>20);
    fflush(stdin);
    system("cls");
    return info;
}
node * insert_at_beg(node * head,data info)
{
    float sum=0;
    node * newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->infor.Nom,info.Nom);
    strcpy(newnode->infor.Prenom,info.Prenom);
    strcpy(newnode->infor.CNE,info.CNE);
    for(int i=0; i<4; i++)
    {
        newnode->infor.notes[i]=info.notes[i];
        sum+=newnode->infor.notes[i];
    }
    newnode->infor.moyenne=sum/4;
    newnode->link=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        newnode->link=head;
        head=newnode;
    }
    return head;
}
node * insert_at_end(node * head,data info)
{
    float sum=0;
    node * newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->infor.Nom,info.Nom);
    strcpy(newnode->infor.Prenom,info.Prenom);
    strcpy(newnode->infor.CNE,info.CNE);
    for(int i=0; i<4; i++)
    {
        newnode->infor.notes[i]=info.notes[i];
        sum+=newnode->infor.notes[i];
    }
    newnode->infor.moyenne=sum/4;
    newnode->link=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        node * ptr=head;
        while(ptr->link!=NULL)
            ptr=ptr->link;
        ptr->link=newnode;
    }
    return head;
}
void affichage(node* head)
{
    node* ptr = head;
    if (head == NULL)
    {
        printf("\n\tThe list is empty.\n");
        return;
    }
    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("|  %-15s|  %-15s|  %-15s|  %-8s|  %-8s|  %-8s|  %-8s|  %-8s|\n", "Nom", "Prenom", "CNE", "SD", "BD", "SE", "AN", "Moyenne");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    while (ptr != NULL)
    {
        printf("|  %-15s|  %-15s|  %-15s|  %-8.2f|  %-8.2f|  %-8.2f|  %-8.2f|  %-8.2f|\n", ptr->infor.Nom, ptr->infor.Prenom, ptr->infor.CNE,
               ptr->infor.notes[0], ptr->infor.notes[1],
               ptr->infor.notes[2], ptr->infor.notes[3],
               ptr->infor.moyenne);
        ptr = ptr->link;
    }
    printf("--------------------------------------------------------------------------------------------------------------\n");
}
void Etudiant(node * head)
{
    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("|  %-15s|  %-15s|  %-15s|  %-8s|  %-8s|  %-8s|  %-8s|  %-8s|\n", "Nom", "Prenom", "CNE", "SD", "BD", "SE", "AN", "Moyenne");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("|  %-15s|  %-15s|  %-15s|  %-8.2f|  %-8.2f|  %-8.2f|  %-8.2f|  %-8.2f|\n", head->infor.Nom, head->infor.Prenom, head->infor.CNE,
           head->infor.notes[0], head->infor.notes[1],
           head->infor.notes[2], head->infor.notes[3],
           head->infor.moyenne);
}
void print_module(node * head,int i)
{
    node* ptr = head;
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    printf("------------------------------------------------------------------\n");
    printf("|  %-15s|  %-15s|  %-15s|  %-8s|\n", "Nom", "Prenom", "CNE", "Notes");
    printf("------------------------------------------------------------------\n");
    while (ptr != NULL)
    {
        printf("|  %-15s|  %-15s|  %-15s|  %-8.2f|\n", ptr->infor.Nom, ptr->infor.Prenom, ptr->infor.CNE, ptr->infor.notes[i]);
        ptr = ptr->link;
    }
    printf("------------------------------------------------------------------\n");
}
void Print(node * head,int i)
{
    printf("|  %-15s|  %-15s|  %-15s|  %-8.2f|\n", head->infor.Nom, head->infor.Prenom, head->infor.CNE,head->infor.notes[i]);
}
node * rechercheetudiant_par_CNE(node * head,char *S)
{
    node*ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(ptr->infor.CNE,S)==0)
        {
            return ptr;
        }
        else
            ptr=ptr->link;
    }
    return NULL;
}
node * rechercheetudiant_par_Nom_Prenom(node * head,char * nom,char * prenom)
{
    node*ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        if(!strcmp(ptr->infor.Nom,nom)&&!strcmp(ptr->infor.Prenom,prenom))
        {
            return ptr;
        }
        else
            ptr=ptr->link;
    }
    return NULL;
}
node * supprimeretudiant_par_CNE(node * head,char * S)
{
    node*ptr=head;
    node * tmp=NULL;
    if((strcmp(ptr->infor.CNE,S)==0))
    {
        head=ptr->link;
        free(ptr);
        ptr=NULL;
        return head;
    }
    while(ptr!=NULL)
    {
        if(strcmp(ptr->infor.CNE,S)==0)
        {
            tmp->link=ptr->link;
            free(ptr);
            ptr=NULL;
            return head;
        }
        else
        {
            tmp=ptr;
            ptr=ptr->link;
        }
    }
    return head;
}
node * supprimeretudiant_par_Nom_Prenom(node * head,char * nom,char * prenom)
{
    node*ptr=head;
    node * tmp=NULL;
    if(!strcmp(ptr->infor.Nom,nom)&&!strcmp(ptr->infor.Prenom,prenom))
    {
        head=ptr->link;
        free(ptr);
        ptr=NULL;
        return head;
    }
    while(ptr!=NULL)
    {
        if(!strcmp(ptr->infor.Nom,nom)&&!strcmp(ptr->infor.Prenom,prenom))
        {
            tmp->link=ptr->link;
            free(ptr);
            ptr=NULL;
            return head;
        }
        else
        {
            tmp=ptr;
            ptr=ptr->link;
        }
    }
    return head;
}
node * trie_par_moyenne(node*head,int ordre)
{
    node * i,*j;
    data tmp;
    for(i=head; i->link!=NULL; i=i->link)
        for(j=i->link; j!=NULL; j=j->link)
            if((ordre==1)?(j->infor.moyenne>i->infor.moyenne):(j->infor.moyenne<i->infor.moyenne))
            {
                tmp=i->infor;
                i->infor=j->infor;
                j->infor=tmp;
            }
    return head;
}
node * trie_par_CNE(node*head,int ordre)
{
    node * i,*j;
    data tmp;
    for(i=head; i->link!=NULL; i=i->link)
        for(j=i->link; j!=NULL; j=j->link)
            if((ordre==1)?(strcmp(j->infor.CNE,i->infor.CNE)>0):(strcmp(j->infor.CNE,i->infor.CNE)<0))
            {
                tmp=i->infor;
                i->infor=j->infor;
                j->infor=tmp;
            }
    return head;
}
node * trie_par_NOM(node*head,int ordre)
{
    node * i,*j;
    data tmp;
    for(i=head; i->link!=NULL; i=i->link)
        for(j=i->link; j!=NULL; j=j->link)
            if((ordre==1)?(strcmp(j->infor.Nom,i->infor.Nom)>0):(strcmp(j->infor.Nom,i->infor.Nom)<0))
            {
                tmp=i->infor;
                i->infor=j->infor;
                j->infor=tmp;
            }
    return head;
}
node * trie_par_Module(node*head,int k,int ordre)
{
    node * i,*j;
    data tmp;
    for(i=head; i->link!=NULL; i=i->link)
        for(j=i->link; j!=NULL; j=j->link)
            if((ordre==1)?(j->infor.notes[k]>i->infor.notes[k]):(j->infor.notes[k]<i->infor.notes[k]))
            {
                tmp=i->infor;
                i->infor=j->infor;
                j->infor=tmp;
            }
    return head;
}
void Affichage_5_Premier_Etudiants(node * head,int i)
{
    node * ptr=NULL;
    if(head==NULL)
    {
        printf("\n\n\t\tList is already empty.\n");
        return ;
    }
    ptr=trie_par_Module(head,i,1);
    node * tmp=ptr;
    int j=0;
    printf("------------------------------------------------------------------\n");
    printf("|  %-15s|  %-15s|  %-15s|  %-8s|\n", "Nom", "Prenom", "CNE", "Notes");
    printf("------------------------------------------------------------------\n");
    while(tmp!=NULL&&j<5&&tmp->infor.notes[i]>=12)
    {
        Print(tmp,i);
        tmp=tmp->link;
        j++;
    }
}
int Nbr_etudiant_valider_Module(node * head,int i)
{
    node * ptr=head;
    int count=0;
    if(head==NULL)
    {
        printf("\n\tList is empty");
        return count ;
    }
    printf("------------------------------------------------------------------\n");
    printf("|  %-15s|  %-15s|  %-15s|  %-8s|\n", "Nom", "Prenom", "CNE", "Notes");
    printf("------------------------------------------------------------------\n");
    while(ptr!=NULL)
    {
        if(ptr->infor.notes[i]>=12)
        {

            Print(ptr,i);
            count++;
            ptr=ptr->link;
        }
        else
            ptr=ptr->link;
    }
    return count;
}
int Nbr_etudiant_Nonvalider_Module(node * head,int i)
{
    node * ptr=head;
    int count=0;
    if(head==NULL)
    {
        printf("\n\tList is empty");
        return count;
    }
    printf("------------------------------------------------------------------\n");
    printf("|  %-15s|  %-15s|  %-15s|  %-8s|\n", "Nom", "Prenom", "CNE", "Notes");
    printf("------------------------------------------------------------------\n");
    while(ptr!=NULL)
    {
        if(ptr->infor.notes[i]<6)
        {
            Print(ptr,i);
            count++;
            ptr=ptr->link;
        }
        else
            ptr=ptr->link;
    }
    return count;
}
int Nbr_etudiant_Rate(node * head,int i)
{
    node * ptr=head;
    int count=0;
    if(head==NULL)
    {
        printf("\n\tList is empty");
        return count;
    }
    printf("------------------------------------------------------------------\n");
    printf("|  %-15s|  %-15s|  %-15s|  %-8s|\n", "Nom", "Prenom", "CNE", "Notes");
    printf("------------------------------------------------------------------\n");
    while(ptr!=NULL)
    {
        if(ptr->infor.notes[i]>=6&&ptr->infor.notes[i]<12)
        {
            Print(ptr,i);
            count++;
            ptr=ptr->link;
        }
        else
            ptr=ptr->link;
    }
    return count;
}
node * supprimerlist(node * head)
{
    node * ptr=head;
    if(head==NULL)
    {
        printf("\n\tList is already empty\n");
        return head ;
    }
    else if(head->link==NULL)
    {
        free(head);
        head=NULL;
        return head;
    }
    else
    {
        while(ptr!=NULL)
        {
            head=head->link;
            free(ptr);
            ptr=head;
        }
    }
    return head;
}
