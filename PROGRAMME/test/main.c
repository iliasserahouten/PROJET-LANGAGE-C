#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
typedef struct {
    char nom[20], prenom[20];
    char id[100];  // nom d'utilisateur //
    char mot_de_passe[20];
    int type_utilisateur;  // 1 = administration, 2 = professeur, 3 = étudiant
}utilisateur;
typedef struct{
    char cne[30];
    char nom[10];
    char prenom[10];
    char cycle[10];
    char filiére[10];
    char semestre[10];
}etud;
typedef struct {
    char Nom[20];
    char Prenom[20];
    char Email[100];
}Prof;
typedef struct{
    char jour[10],mois[10],annee[10],heure[10],minute[10];
} date;
typedef struct {
    char moduleName[100];  // nom du module //
    char professor[100];
    char Cycle[10];// nom professeur //
    char Filiére[10];
    char Semestre[10];
} Module;
typedef struct {
    char AmphiBloc[20];
    char salle [20];
} Salles;
typedef struct {
Module m;
char dat[20];
char duree[20];
}Exam;
// Fonction pour afficher du texte au milieu de la console
void setColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor | (bgColor << 4));
}
void printCenteredTextWithColor(const char *text, int textColor, int bgColor) {
    // Set console text color and background color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor | (bgColor << 4));

    // Calculate centering
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    int textLength = strlen(text);
    int leftPadding = (consoleWidth - textLength) / 2;

    // Print centered text
    printf("%*s%s\n", leftPadding, " ", text);

    // Reset console colors
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Restores default colors

}
void loading() {
    system("cls");

    printf("\n\n\n");

    // Print centered text with cyan text and black background
    printCenteredTextWithColor("", FOREGROUND_GREEN | FOREGROUND_BLUE, 0);
    system("cls");
    for (int a = 0; a <= 100; a += 5) {
        printf("                                      ");

        for (int i = 0; i < a / 2; ++i) {
            if (i % 2 == 0) {
                printf("\x1b[36m%c\x1b[0m", 219);
            } else {
                printf("\x1b[35m%c\x1b[0m", 219);
            }
        }

        printf("[%d%%]\n", a);

        Sleep(100);
        system("cls");
        printf("\n\n\n");

        // Print centered text with cyan text and black background
        printCenteredTextWithColor("\t\tLOADING", FOREGROUND_GREEN | FOREGROUND_BLUE, 0);

    }
}
void Consultesurveillance(Prof p){
    char salle[20],surv[20],exam[20];
    Exam e;
    Prof p1, p2 ;
    Salles s;
    FILE *f = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\examen_prof_salle.txt","rt");
    if(f==NULL){
        printf("Erreur lors l'ouverture de fichier");
    }
    else{
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",exam,e.m.moduleName, e.m.professor,e.m.Cycle,e.m.Filiére, e.m.Semestre, e.dat, e.duree,surv,p2.Nom, p2.Prenom, p1.Nom, p1.Prenom, salle ,s.AmphiBloc, s.salle)==16){
            if ((strcmp(p.Nom,p2.Nom)==0 && strcmp(p.Prenom,p2.Prenom)==0)||(strcmp(p.Nom,p1.Nom)==0 && strcmp(p.Prenom,p1.Prenom)==0)){
                printf("--------------------------------------------------------------------------------------------------\n");
                printf("\t\t\t\t\t%s %s %s %s %s %s %s %s \n", exam, e.m.moduleName, e.m.professor, e.m.Cycle,e.m.Filiére, e.m.Semestre,e.dat,e.duree);
                printf("--------------------------------------------------------------------------------------------------\n");
                printf("\t\t\t\t\t%s %s %s  %s\n", surv, salle, s.AmphiBloc, s.salle);
            }
        }
    }
    fclose(f);
};
void ConsulteExams(Prof p) {
    char salle[20], surv[20], exam[20];
    Exam e;
    Prof examProf, p1;
    Salles s;

    FILE *f = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\examen_prof_salle.txt", "rt");

    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
    } else {
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",exam, e.m.moduleName, e.m.professor, e.m.Cycle, e.m.Filiére, e.m.Semestre, e.dat, e.duree,surv, examProf.Nom, examProf.Prenom, p1.Nom, p1.Prenom, salle, s.AmphiBloc, s.salle) == 16) {
            if (strcmp(p.Nom,e.m.professor) == 0) {
                printf("--------------------------------------------------------------------------------------------------\n");
                printf("\t\t\t\t\t%s %s %s %s %s %s %s \n", exam, e.m.moduleName, e.m.Cycle, e.m.Filiére,e.m.Semestre, e.dat, e.duree);
                printf("--------------------------------------------------------------------------------------------------\n");
                printf("\t\t\t\t%s %s %s %s\n", salle, s.AmphiBloc, s.salle);
            }
        }
    }
    fclose(f);
}
void AfficherExams(){
    FILE *f = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\examen_prof_salle.txt", "rt");

    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return;
    }

    char exam[20], surv[20], salle[20];
    Exam e, e1;
    Prof p[10];
    Salles s;

    while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
                  exam, e.m.moduleName, e.m.professor, e.m.Cycle, e.m.Filiére, e.m.Semestre,e.dat,e.duree,
                  surv, p[0].Nom, p[0].Prenom, p[1].Nom, p[1].Prenom, salle, s.AmphiBloc, s.salle) == 16) {

        printf("--------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\t\t%s %s %s %s %s %s %s %s \n", exam, e.m.moduleName, e.m.professor, e.m.Cycle,
               e.m.Filiére, e.m.Semestre,e.dat,e.duree);
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("\t\t%s %s %s %s %s %s %s %s\n", surv, p[0].Nom, p[0].Prenom, p[1].Nom, p[1].Prenom, salle, s.AmphiBloc, s.salle);

        do {
            if (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
                       exam, e1.m.moduleName, e1.m.professor, e1.m.Cycle, e1.m.Filiére, e1.m.Semestre,e1.dat,e1.duree,
                       surv, p[2].Nom, p[2].Prenom, p[3].Nom, p[3].Prenom, salle, s.AmphiBloc, s.salle) != 16) {
                break; // Arrête la boucle s'il n'y a pas assez d'éléments à lire
            }

            if (strcasecmp(e.m.moduleName, e1.m.moduleName) != 0) {
                printf("--------------------------------------------------------------------------------------------------\n");
                printf("\t\t\t\t\t%s %s %s %s %s %s %s %s \n", exam, e1.m.moduleName, e1.m.professor, e1.m.Cycle,
                       e1.m.Filiére, e1.m.Semestre,e1.dat,e1.duree);
                printf("--------------------------------------------------------------------------------------------------\n");
                printf("%s %s %s %s %s %s %s %s\n", surv, p[2].Nom, p[2].Prenom, p[3].Nom, p[3].Prenom, salle, s.AmphiBloc, s.salle);
                strcpy(e.m.moduleName, e1.m.moduleName);
            } else {
                printf("%s %s %s %s %s %s %s %s\n", surv, p[2].Nom, p[2].Prenom, p[3].Nom, p[3].Prenom, salle, s.AmphiBloc, s.salle);
            }
        } while (!feof(f));
    }

    fclose(f);
};
void RemplireExam(){
    Exam e;
    Prof p, p1,p2;
    Salles s;

    FILE *f = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Exam.txt", "rt");
    FILE *f1 = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Prof.txt", "rt");
    FILE *f2 = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Salle.txt", "rt");
    FILE *f3 = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\examen_prof_salle.txt", "wt");

    if (f == NULL || f1 == NULL || f2 == NULL || f3 == NULL) {
        printf("Erreur lors de l'ouverture des fichiers\n");
        return; // Quitter le programme en cas d'échec de l'ouverture des fichiers
    }

    while (fscanf(f, "%s%s%s%s%s%s%s", e.m.moduleName, e.m.professor, e.m.Cycle, e.m.Filiére, e.m.Semestre, e.dat, e.duree) == 7 ) {
        if(feof(f1)) {
            fseek(f1, 0, SEEK_SET);
        }
        fseek(f2,0,SEEK_SET);
        while(fscanf(f1, "%s%s%s", p.Nom, p.Prenom,p.Email)==3 && fscanf(f1, "%s%s%s", p1.Nom, p1.Prenom,p1.Email)==3 && fscanf(f2, "%s%s", s.AmphiBloc, s.salle)==2){

            if(strcasecmp(s.AmphiBloc,"amphi")==0){
                fprintf(f3,
                        "Exam: %s %s %s %s %s %s %s surveillance: %s %s %s %s Salle: %s %s\n",
                        e.m.moduleName, e.m.professor, e.m.Cycle, e.m.Filiére, e.m.Semestre, e.dat, e.duree,
                        p.Nom, p.Prenom, p1.Nom, p1.Prenom, s.AmphiBloc, s.salle);
            }else if(strcasecmp(s.AmphiBloc,"BlocB")!=0 && strcasecmp(e.m.Cycle,"CP")==0 ) {
                fprintf(f3, "Exam: %s %s %s %s %s %s %s surveillance: %s %s %s %s  Salle: %s %s\n",
                        e.m.moduleName, e.m.professor, e.m.Cycle, e.m.Filiére, e.m.Semestre, e.dat, e.duree,
                        p.Nom, p.Prenom, p1.Nom, p1.Prenom, s.AmphiBloc, s.salle);
            }
        }
    }

    fclose(f);
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
void afficherModules() {
    FILE *f = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Module.txt", "rt");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture de fichier ");
        return;
    } else {
        Module a;
        Module a1;
        printf("entrer votre cycle (CP ou CI) : ");
        scanf("%s", a1.Cycle);
        if (strcasecmp(a1.Cycle, "CP") == 0 ) {
            while (fscanf(f, "%s %s %s %s %s", a.moduleName, a.professor, a.Cycle, a.Filiére, a.Semestre) == 5) {
                if (strcasecmp(a1.Cycle, a.Cycle) == 0) {
                    printf("%s %s %s %s %s\n", a.moduleName, a.professor, a.Cycle, a.Filiére, a.Semestre);
                }
            }
        } else if (strcmp(a1.Cycle, "CI") == 0 || strcmp(a1.Cycle, "ci") == 0) {
            while (fscanf(f, "%s %s %s %s %s", a.moduleName, a.professor, a.Cycle, a.Filiére, a.Semestre) == 5) {
                if (strcmp(a1.Cycle, a.Cycle) == 0) {
                    printf("%s %s %s %s %s\n", a.moduleName, a.professor, a.Cycle, a.Filiére, a.Semestre);
                }
            }
        }
    }
    fclose(f);
}
void AjouterModules() {
    Module a,a1;
    Exam d1 , d2 ;

    FILE *fs = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Module.txt", "at");
    FILE *fe = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Exam.txt", "at");
    if (fs == NULL || fe==NULL) {
        printf("Erreur lors  l'ouverture de fichier");
        return;
    } else {
        printf("entrer nom de module : ");
        scanf("%s", a.moduleName);
        printf("entrer nom de prof : ");
        scanf("%s", a.professor);
        printf("entrer Cycle : ");
        scanf("%s", a.Cycle);
        if (strcasecmp(a.Cycle, "cp") == 0) {
            strcpy(a.Filiére, "--");
        } else {
            printf("entre votre Filiere : ");
            scanf("%s", a.Filiére);
        }
        printf("entrer votre semestre : ");
        scanf("%s", a.Semestre);
        printf("entrer la date de l'examen : ");
        scanf("%s",d1.dat);
        printf("entrer la duree de l'examen : ");
        scanf("%s",d1.duree);
        bool datetrouver = false;
        bool heuretrouver=false;
        while (fscanf(fe, "%s %s %s %s %s %s %s", a1.moduleName, a1.professor, a1.Cycle, a1.Filiére, a1.Semestre,d2.dat,d2.duree ) == 7) {
            if (strcasecmp(d1.dat,d2.dat)==0 )
                datetrouver = true;
            if(strcasecmp(d1.duree , d2.duree)==0)
                heuretrouver=true;
        }
        if (!datetrouver) {
            fprintf(fs, "\n%s %s %s %s %s", a.moduleName, a.professor, a.Cycle, a.Filiére, a.Semestre);
            fprintf(fe, "\n%s %s %s %s %s %s %s", a.moduleName, a.professor, a.Cycle, a.Filiére,
                        a.Semestre, d1.dat , d1.duree);

        }else {
            if (!heuretrouver) {
                fprintf(fs, "\n%s %s %s %s %s", a.moduleName, a.professor, a.Cycle, a.Filiére, a.Semestre);
                fprintf(fe, "\n%s %s %s %s %s %s %s", a.moduleName, a.professor, a.Cycle, a.Filiére, a.Semestre,  d1.dat , d1.duree);
            } else {
                printf("cette date et heure sont deja reservee");
                return;
            }
        }
    }
    fclose(fs);
    fclose(fe);
    RemplireExam();
}
void supprimerModules() {
    Module a1;
    Module a;
    Exam d2;
    FILE *fes = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Exam.txt", "rt");
    FILE *fec = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\exam1.txt", "wt");
    FILE *fs = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Module.txt", "rt");
    FILE *fc = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Module1.txt", "wt");
    if ((fs == NULL || fc == NULL || fes == NULL || fec == NULL)) {
        printf("Erreur lors de l'ouverture de fichier");
    } else {
        printf("Entrer les informations de modules a supprimer : \n");
        printf("Entrer le nom de module : ");
        scanf("%s", a1.moduleName);

        printf("Entrer le prof : ");
        scanf("%s", a1.professor);

        printf("Entrer le Cycle  : ");
        scanf("%s", a1.Cycle);

        if (strcasecmp(a1.Cycle, "cp") == 0) {
            strcpy(a1.Filiére, "--");
        } else {
            printf("entre la Filiere : ");
            scanf("%s", a1.Filiére);

        }
        printf("Entrer le semestre : ");
        scanf("%s", a1.Semestre);
        bool module_trouve=false;
        while (fscanf(fs, "%s %s %s %s %s", a.moduleName, a.professor, a.Cycle, a.Filiére, a.Semestre) == 5 && fscanf(fes, "%s %s %s %s %s %s %s", a.moduleName, a.professor, a.Cycle, a.Filiére, a.Semestre,d2.dat,d2.duree ) == 7 ){
            if (strcmp(a.moduleName, a1.moduleName) == 0 && strcmp(a.professor, a1.professor) == 0 &&
                strcmp(a.Cycle, a1.Cycle) == 0 && strcmp(a.Filiére, a1.Filiére) == 0 &&
                strcmp(a.Semestre, a1.Semestre) == 0 ) {
                module_trouve = true;
            } else {
                fprintf(fc,"\n%s %s %s %s %s", a.moduleName, a.professor, a.Cycle, a.Filiére, a.Semestre);
                fprintf(fec,"\n%s %s %s %s %s %s %s", a.moduleName, a.professor, a.Cycle, a.Filiére, a.Semestre,d2.dat,d2.duree);
            }
        }

        fclose(fs);
        fclose(fc);
        fclose(fes);
        fclose(fec);
        if (!module_trouve) {
            remove("C:\\Users\\Iliass\\CLionProjects\\test\\Module1.txt");
            remove("C:\\Users\\Iliass\\CLionProjects\\test\\exam1.txt");
            printf("Module non trouve.\n");
        } else {
            remove("C:\\Users\\Iliass\\CLionProjects\\test\\Module.txt");
            remove("C:\\Users\\Iliass\\CLionProjects\\test\\Exam.txt");
            rename("C:\\Users\\Iliass\\CLionProjects\\test\\Module1.txt",
                   "C:\\Users\\Iliass\\CLionProjects\\test\\Module.txt");
            rename("C:\\Users\\Iliass\\CLionProjects\\test\\exam1.txt",
                   "C:\\Users\\Iliass\\CLionProjects\\test\\Exam.txt");
            printf("module supprimees avec sucees\n");
        }
    }
    RemplireExam();
}
void Modifiermodule() {
    Module a,ae;
    Module a1;
    Exam d2;
    int moduletrouv = 0;
    FILE *fes = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Exam.txt", "rt");
    FILE *fec = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\exam1.txt", "wt");
    FILE *fs = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Module.txt", "rt");
    FILE *fc = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Module2.txt", "wt");
    if (fs == NULL || fc == NULL) {
        printf("Erreur lors de l'ouverture de fichier");
        return;
    } else {
        printf("Entrer les   infos de module  a modifier : \n");
        printf("Entrer le nom de module  : ");
        scanf("%s", a1.moduleName);
        printf("entrer le prof : ");
        scanf("%s", a1.professor);
        printf("Entrer le Cycle  : ");
        scanf("%s", a1.Cycle);
        if (strcasecmp(a1.Cycle, "cp") == 0) {
            strcpy(a1.Filiére, "--");
        } else {
            printf("entre la Filiere : ");
            scanf("%s", a1.Filiére);
        }
        printf("Entrer le semestre : ");
        scanf("%s", a1.Semestre);
        while (fscanf(fs, "%s %s %s %s %s", a.moduleName, a.professor, a.Cycle, a.Filiére, a.Semestre) == 5 && fscanf(fes, "%s %s %s %s %s %s %s", a.moduleName, a.professor, a.Cycle, a.Filiére, a.Semestre, d2.dat, d2.duree ) == 7){
            if (strcmp(a1.moduleName, a.moduleName) == 0 && strcmp(a1.professor, a.professor) == 0 &&
                strcmp(a1.Cycle, a.Cycle) == 0 && strcmp(a1.Filiére, a.Filiére) == 0 &&
                strcmp(a1.Semestre, a.Semestre) == 0){
                moduletrouv = 1;
                printf("Entrez les nouvelles donnees : \n");
                printf("Entrer le nouveau nom de module : ");
                scanf("%s", a.moduleName);
                printf("Entrer le nouveau prof : ");
                scanf("%s", a.professor);
                printf("Entrer le nouveau Cycle : ");
                scanf("%s", a.Cycle);
                printf("Entrer la nouvelle Filiere : ");
                scanf("%s", a.Filiére);
                printf("Entrer le nouveau semestre : ");
                scanf("%s", a.Semestre);
            }
            fprintf(fc, "%s %s %s %s %s\n", a.moduleName, a.professor, a.Cycle, a.Filiére, a.Semestre);
            fprintf(fec, "%s %s %s %s %s %s %s\n", a.moduleName, a.professor, a.Cycle, a.Filiére, a.Semestre,d2.dat,d2.duree);
        }

        fclose(fs);
        fclose(fc);
        fclose(fes);
        fclose(fec);

        if (!moduletrouv) {
            printf("Module non trouve. Aucune modification effectuee.\n");
        } else {
            remove("C:\\Users\\Iliass\\CLionProjects\\test\\Module.txt");
            remove("C:\\Users\\Iliass\\CLionProjects\\test\\Exam.txt");
            rename("C:\\Users\\Iliass\\CLionProjects\\test\\Module2.txt",
                   "C:\\Users\\Iliass\\CLionProjects\\test\\Module.txt");
            rename("C:\\Users\\Iliass\\CLionProjects\\test\\exam1.txt",
                   "C:\\Users\\Iliass\\CLionProjects\\test\\Exam.txt");
            printf("Module modifie avec succès\n");
        }
    }
}
int AfficherMenuAdmin();
void AfficherSousMenuAdmin(int option);
void AffecterProfExam(){
    printf("Voulez-vous affecter des professeurs à des examens (oui/non) ");
    char answer[10];
    scanf("%s", answer);

    if (strcasecmp(answer, "oui") == 0) { // Utilisation de strcasecmp pour la comparaison insensible à la casse
        FILE *fe = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Exam.txt", "rt");
        FILE *fp = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Prof.txt", "rt");
        FILE *fs = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Salle.txt", "rt");

        if (fe == NULL || fp == NULL || fs == NULL) {
            printf("Erreur lors de l'ouverture du fichier\n");
            return;
        }
        Prof p,p1,p2;
        printf("Saisir le nom et le prenom du 1er professeur à affecter : ");
        scanf("%s%s", p.Nom, p.Prenom);
        printf("Saisir le nom et le prenom du 2eme professeur à affecter : ");
        scanf("%s%s", p2.Nom, p2.Prenom);
        bool professeurTrouve = false;
        while (fscanf(fp, "%s%s%s", p1.Nom, p1.Prenom, p1.Email) == 3){
            if (strcasecmp(p1.Nom, p.Nom) == 0 && strcasecmp(p.Prenom, p1.Prenom) == 0) {
                printf("Professeur trouve\n");
                professeurTrouve = true;
                break;
            }
        }
        while (fscanf(fp, "%s%s%s", p1.Nom, p1.Prenom, p1.Email) == 3){
            if (strcasecmp(p1.Nom, p2.Nom) == 0 && strcasecmp(p2.Prenom, p1.Prenom) == 0) {
                printf("Professeur trouve\n");
                professeurTrouve = true;
                break;
            }
        }
        if (!professeurTrouve) {
            printf("Professeur non trouve\n");

            return;
        }
        Exam e;
        Exam e1;
        printf("Saisir le nom du module de l'examen à affecter : ");
        scanf("%s", e.m.moduleName);
        bool examenTrouve = false;
        // Utiliser fread avec sizeof(Exam) pour lire la structure correctement
        while (fscanf(fe,"%s%s%s%s%s%s%s",e1.m.moduleName,e1.m.professor,e1.m.Cycle,e1.m.Filiére,e1.m.Semestre,e1.dat,e1.duree) == 7) {
            if (strcasecmp(e.m.moduleName, e1.m.moduleName) == 0) {
                printf("Examen trouve\n");
                examenTrouve = true;
                break;
            }
        }
        if (!examenTrouve) {
            printf("Examen non trouve\n");
            AfficherMenuAdmin();
            return;
        }
        Salles s, s1;
        printf("Saisir le bloc et la salle où affecter : ");
        scanf("%s%s", s.AmphiBloc, s.salle);
        bool salleTrouve = false;
        // Utiliser fread avec sizeof(Salles) pour lire la structure correctement
        while (fscanf(fs,"%s%s",s1.AmphiBloc,s1.salle) == 2) {
            if (strcasecmp(s.AmphiBloc, s1.AmphiBloc) == 0 && strcasecmp(s.salle, s1.salle) == 0) {
                printf("Salle trouvee\n");
                salleTrouve = true;
                break;
            }
        }
        if (!salleTrouve) {
            printf("salle non trouve\n");
            AfficherMenuAdmin();
            return;
        }
        FILE *fex = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\examen_prof_salle.txt", "at");
        if (fex == NULL) {
            printf("Erreur lors de l'ouverture du fichier\n");
            return;
        }
        if (professeurTrouve && examenTrouve && salleTrouve){
            fprintf(fex, "Exam: %s %s %s %s %s %s %s surveillance:Pr.%s %s %s %s Salle: %s %s\n", e1.m.moduleName,
                    e1.m.professor, e1.m.Cycle, e1.m.Filiére, e1.m.Semestre, e1.dat, e1.duree, p1.Nom, p1.Prenom, p2.Nom, p2.Prenom,
                    s1.AmphiBloc, s1.salle);
            fclose(fe);
            fclose(fp);
            fclose(fs);
            fclose(fex);
        }else{
            printf("les donnes sont incorrectes");
            AfficherSousMenuAdmin(AfficherMenuAdmin());
        }
    }else AfficherMenuAdmin();
}
void GererSalleHoraire() {
    int choix, souschoix;
    printf("\n\n\n\n");
    printf("\t\t\t\t");
    printf("\n\n\n\n");
    printf("        ------------------------------------------------------------------\n");
    printf("        |\t\t 1) Gerer les salles                           |\n");
    printf("        |\t\t 2) Gerer horaires                             |\n");
    printf("        |\t\t 3) Retour                                     |\n");
    printf("        |\t\t 4) Quitter                                    |\n");
    printf("        -----------------------------------------------------------------\n");
    printf(" \t\t Entrez votre choix: ");
    scanf("%d", &choix);
    switch (choix) {
        case 1:
            printf("\n\n\n\n");
            printf("\t\t\t\t");
            printf("\n\n\n\n");
            printf("        ------------------------------------------------------------------\n");
            printf("        |\t\t 1) Ajouter des salles                        |\n");
            printf("        |\t\t 2) Supprimer des salles                      |\n");
            printf("        |\t\t 3) Retour                                     |\n");
            printf("        |\t\t 4) Quitter                                    |\n");
            printf("        -----------------------------------------------------------------\n");
            printf(" \t\t Entrez votre choix: ");
            scanf("%d", &souschoix);
            switch (souschoix) {
                case 1:
                    printf("Voulez-vous ajouter une salle (oui/non): ");
                    char answer1[5];
                    scanf("%s", answer1);

                    if (strcasecmp(answer1, "oui") == 0) {
                        Salles s, s1;
                        printf("Les salles sont : \n");

                        FILE *f = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Salle.txt", "rt");
                        if (f == NULL) {
                            printf("Erreur lors de l'ouverture du fichier 'Salle.txt'\n");
                            return; // Quitter le programme en cas d'erreur
                        }

                        while (fscanf(f, "%s%s", s1.AmphiBloc, s1.salle) == 2) {
                            printf("%s %s \n", s1.AmphiBloc, s1.salle);
                        }

                        fclose(f);

                        printf("Ajouter une salle d'examen : Amphi ou Bloc (A/B): ");
                        scanf("%s", s.AmphiBloc);

                        if (strcasecmp(s.AmphiBloc, "amphi") == 0) {
                            printf("Amphi A/B? ");
                            scanf("%s", s.salle);

                            bool salleTrouver = false;

                            FILE *f = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Salle.txt", "rt");
                            if (f == NULL) {
                                printf("Erreur d'ouverture du fichier\n");
                                return; // Quitter le programme en cas d'erreur
                            }

                            while (fscanf(f, "%s%s", s1.AmphiBloc, s1.salle) == 2) {
                                if (strcasecmp(s1.AmphiBloc, s.AmphiBloc) == 0 && strcasecmp(s1.salle, s.salle) == 0) {
                                    salleTrouver = true;
                                }
                            }

                            fclose(f);

                            if (!salleTrouver) {
                                FILE *f = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Salle.txt", "at");
                                fprintf(f, "\n%s %s", s.AmphiBloc, s.salle);
                                fclose(f);
                            } else {
                                printf("Salle deja existante\n");
                                return; // Quitter le programme en cas de salle existante
                            }
                        } else if (strcasecmp(s.AmphiBloc, "blocA") == 0 || strcasecmp(s.AmphiBloc, "blocB") == 0) {
                            FILE *f = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Salle.txt", "at");

                            printf("Saisie le numero de la salle dans %s (salle..): ", s.AmphiBloc);
                            scanf("%s", s.salle);

                            bool salleTrouver = false;

                            while (fscanf(f, "%s%s", s1.AmphiBloc, s1.salle) == 2) {
                                if (strcasecmp(s1.AmphiBloc, s.AmphiBloc) == 0 && strcasecmp(s1.salle, s.salle) == 0) {
                                    salleTrouver = true;
                                }
                            }

                            if (!salleTrouver) {
                                fprintf(f, "\n%s %s", s.AmphiBloc, s.salle);
                            } else {
                                printf("Salle deja existante\n");
                                fclose(f);
                                return; // Quitter le programme en cas de salle existante
                            }

                            fclose(f);

                        }
                    } else {
                        printf("Au revoir");
                        return;
                    }
                    RemplireExam();
                    break;
                case 2:
                    printf("Voulez-vous supprimer une salle (oui/non)\n");
                    char answer[5];
                    scanf("%s", answer);

                    if (strcasecmp(answer, "oui") == 0) {
                        Salles s, s1;
                        printf("Les salles sont : \n");

                        FILE *f = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Salle.txt", "rt");
                        FILE *f1 = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Salle1.txt", "wt");
                        if (f == NULL || f1 == NULL) {
                            printf("Erreur lors de l'ouverture du fichier\n");
                            return;
                        }

                        while (fscanf(f, "%s%s", s1.AmphiBloc, s1.salle) == 2) {
                            printf("%s %s \n", s1.AmphiBloc, s1.salle);
                        }

                        printf("Supprimer une salle d'examen : Amphi ou Bloc (A/B): ");
                        scanf("%s", s.AmphiBloc);

                        if (strcasecmp(s.AmphiBloc, "amphi") == 0) {
                            printf("Amphi A/B? ");
                            scanf("%s", s.salle);
                            rewind(f);
                            while (fscanf(f, "%s%s", s1.AmphiBloc, s1.salle) == 2) {
                                if (strcasecmp(s1.AmphiBloc, s.AmphiBloc) != 0 || strcasecmp(s1.salle, s.salle) != 0) {
                                    fprintf(f1, "\n%s %s ", s1.AmphiBloc, s1.salle);
                                }
                            }
                        } else if (strcasecmp(s.AmphiBloc, "BlocA") == 0 || strcasecmp(s.AmphiBloc, "BlocB") == 0) {
                            printf("Saisir le numero de la salle dans %s (salle..): ", s.AmphiBloc);
                            scanf("%s", s.salle);
                            rewind(f);
                            while (fscanf(f, "%s%s", s1.AmphiBloc, s1.salle) == 2) {
                                if (strcasecmp(s1.AmphiBloc, s.AmphiBloc) != 0 || strcasecmp(s1.salle, s.salle) != 0) {
                                    fprintf(f1, "\n%s %s ", s1.AmphiBloc, s1.salle);
                                }
                            }
                        } else {
                            printf("Type inconnu\n");
                            fclose(f);
                            fclose(f1);
                            return;
                        }

                        fclose(f);
                        fclose(f1);

                        remove("C:\\Users\\Iliass\\CLionProjects\\test\\Salle.txt");
                        rename("C:\\Users\\Iliass\\CLionProjects\\test\\Salle1.txt", "C:\\Users\\Iliass\\CLionProjects\\test\\Salle.txt");
                        printf("salle supprimer avec succes");
                    } else {
                        printf("Au revoir\n");
                    }
                    RemplireExam();
                    break;
                case 3:
                    GererSalleHoraire();
                    break;
                case 4:
                    break;
            }
        case 2:
            printf("Voulez-vous modifier des horaires (oui/non): ");
            char answer[5];
            scanf("%s", answer);

            if (strcasecmp(answer, "non") == 0) {
                printf("Au revoir\n");
                return;
            } else {
                FILE *fs = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\exam.txt", "rt");
                FILE *fc = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\exam1.txt", "wt");

                if (fs == NULL || fc == NULL) {
                    printf("Erreur lors de l'ouverture de fichier\n");
                    return;
                } else {
                    Exam e, e1;
                    date d, f;
                    bool moduleTrouve = false;

                    printf("Entrer les infos de l'exam à modifier :\n");
                    printf("Entrer le nom du module : ");
                    scanf("%s", e.m.moduleName);

                    while (fscanf(fs, "%s %s %s %s %s %s %s", e1.m.moduleName, e1.m.professor, e1.m.Cycle, e1.m.Filiére,
                                  e1.m.Semestre, e1.dat, e1.duree) == 7) {
                        if (strcasecmp(e1.m.moduleName, e.m.moduleName) == 0) {
                            moduleTrouve = true;
                            printf("%s %s %s %s %s %s %s\n", e1.m.moduleName, e1.m.professor, e1.m.Cycle, e1.m.Filiére,
                                   e1.m.Semestre, e1.dat, e1.duree);

                            printf("Entrez les nouvelles donnees :\n");
                            printf("Entrer la nouvelle heure de depart : ");
                            scanf("%s", d.heure);
                            printf("Entrer la nouvelle minute de depart : ");
                            scanf("%s", d.minute);
                            printf("Entrer la nouvelle heure de fin : ");
                            scanf("%s", f.heure);
                            printf("Entrer la nouvelle minute de fin : ");
                            scanf("%s", f.minute);

                            FILE *fe = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\copy.txt", "wt");
                            fprintf(fe, "%s:%s-%s:%s", d.heure, d.minute, f.heure, f.minute);
                            fclose(fe);
                            FILE *f2 = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\copy.txt", "rt");
                            fscanf(f2, "%s", e.duree);
                            fclose(f2);
                            remove("C:\\Users\\Iliass\\CLionProjects\\test\\copy.txt");
                            strcpy(e.dat, e1.dat);
                            break;
                        }
                    }

                    fclose(fs);
                    fclose(fc);

                    if (!moduleTrouve) {
                        remove("C:\\Users\\Iliass\\CLionProjects\\test\\exam1.txt");
                        printf("Module non trouve. Aucune modification effectuee.\n");
                        return;
                    }

                    fs = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\exam.txt", "rt");
                    fc = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\exam1.txt", "wt");

                    bool horaireIndispo = false;

                    while (fscanf(fs, "%s %s %s %s %s %s %s", e1.m.moduleName, e1.m.professor, e1.m.Cycle, e1.m.Filiére,
                                  e1.m.Semestre, e1.dat, e1.duree) == 7) {
                        if (strcasecmp(e1.dat, e.dat) == 0 && strcasecmp(e1.duree, e.duree) == 0) {
                            horaireIndispo = true;
                            break;
                        }
                    }
                    if(horaireIndispo){
                        printf("horaire non disponible");
                        return;
                    }else {
                        rewind(fs); // Remettre le curseur au début du fichier
                        printf("horaire  disponible");
                        while (fscanf(fs, "%s %s %s %s %s %s %s", e1.m.moduleName, e1.m.professor, e1.m.Cycle,
                                      e1.m.Filiére, e1.m.Semestre, e1.dat, e1.duree) == 7) {
                            if (strcasecmp(e1.m.moduleName, e.m.moduleName) == 0) {
                                fprintf(fc, "%s %s %s %s %s %s %s\n", e.m.moduleName, e1.m.professor, e1.m.Cycle,
                                        e1.m.Filiére, e1.m.Semestre, e1.dat, e.duree);
                            } else {
                                fprintf(fc, "%s %s %s %s %s %s %s\n", e1.m.moduleName, e1.m.professor, e1.m.Cycle,
                                        e1.m.Filiére, e1.m.Semestre, e1.dat, e1.duree);
                            }
                        }
                        fclose(fs);
                        fclose(fc);
                        remove("C:\\Users\\Iliass\\CLionProjects\\test\\exam.txt");
                        rename("C:\\Users\\Iliass\\CLionProjects\\test\\exam1.txt", "C:\\Users\\Iliass\\CLionProjects\\test\\exam.txt");
                    }
                }
                RemplireExam();
                break;
            }
        case 3:
            AfficherSousMenuAdmin(AfficherMenuAdmin());
            break;
        case 4:
            printf("Au revoir");
            break;

            }
}
int AfficherMenuAdmin() {

        int option;
    time_t t;
    time(&t);
    printf("\t\t\t\t");
    printf("\n\n\n\n");
        printf( "\n\t\t\t\t                %s\n", ctime(&t));
        printf("\t\t\t\t        ------------------------------------------------------------------\n");
        printf("\t\t\t\t        |\t\t 1) Ajouter/modifier/supprimer des modules         |\n");
        printf("\t\t\t\t        |\t\t 2) Affecter des professeurs a des examens         |\n");
        printf("\t\t\t\t        |\t\t 3) Gerer les salles d'examen et les horaires      |\n");
        printf("\t\t\t\t        |\t\t 4) Afficher planification des examens             |\n");
        printf("\t\t\t\t        |\t\t 5) Quitter                                        |\n");
        printf("\t\t\t\t        -----------------------------------------------------------------\n");
        printf(" \t\t\t\t\t\t Entrez votre choix: ");
            scanf("%d", &option);
            system("cls");
        return option;
    }
void AfficherSousMenuAdmin(int option) {
        int choix;
        switch (option) {
            case 1:
                printf("\n\n\n\n");
                printf("\t\t\t\t");
                printf("\n\n\n\n");
                printf("\t        ------------------------------------------------------------------\n");
                printf("\t        |\t\t 1) Ajouter des modules                           |\n");
                printf("\t        |\t\t 2) Supprimer des modules                         |\n");
                printf("\t        |\t\t 3) Modifier des modules                          |\n");
                printf("\t        |\t\t 4) Retour                                        |\n");
                printf("\t        |\t\t 5) Quitter                                       |\n");
                printf("\t        -----------------------------------------------------------------\n");
                printf(" \t\t Entrez votre choix: ");
                scanf("%d", &choix);
                system("cls");
                switch (choix) {
                    case 1:
                        afficherModules();
                        char c[4];
                        do {
                            printf("voulez-vous ajoutez des modules ? (oui ou non) : ");
                            scanf("%s", c);
                            system("cls");
                        } while (strcmp(c, "OUI") != 0 && strcmp(c, "oui") != 0 && strcmp(c, "non") != 0 &&
                                 strcmp(c, "NON") != 0);
                        if (strcasecmp(c, "oui") == 0) {
                            int n;
                            printf("entrer le nombre de module a ajoute : ");
                            scanf("%d",&n);
                            for(int i=0;i<n;i++){
                            AjouterModules();}
                            RemplireExam();

                        } else if (strcasecmp(c, "non") == 0)
                            AfficherSousMenuAdmin(option);
                        break;
                    case 2:
                        afficherModules();
                        char h[4];
                        do{
                            printf("voulez-vous supprimer des modules ? (oui ou non) : ");
                            scanf("%s", h);
                            system("cls");
                        }while (strcasecmp(h, "non") != 0 && strcasecmp(h, "oui") != 0 );
                        if (strcasecmp(h, "oui") == 0) {
                            int n;
                            printf("entrer le nombre de module a supprimer : ");
                            scanf("%d",&n);
                            for(int i = 0 ; i<n ; i++) {
                                supprimerModules();
                            }
                            RemplireExam();

                        }else if (strcasecmp(h, "non") == 0)
                            AfficherSousMenuAdmin(option);

                        break;
                    case 3:
                        afficherModules();
                        char e[4];
                        do {
                            printf("voulez-vous modifier des modules ? (oui ou non) : ");
                            scanf("%s", e);
                            system("cls");
                        } while (strcasecmp(e, "non") != 0 && strcasecmp(e, "oui") != 0 );

                        if (strcasecmp(e, "oui") == 0) {
                            int n;
                            printf("entrer le nombre de module a modifier : ");
                            scanf("%d", &n);
                            for (int i = 0; i < n; i++) {
                                Modifiermodule();
                            }
                            RemplireExam();

                        } else if (strcasecmp(e, "non") == 0)
                            AfficherSousMenuAdmin(option);
                        break;
                    case 4:
                        AfficherSousMenuAdmin(AfficherMenuAdmin(option));
                        break;
                    case 5:
                        exit(0);
                        break;
                    default :
                        printf("UKnown type");
                }
                break;
            case 2:
                AffecterProfExam();
                printf("\n\t\tAppuyez sur une touche pour continuer");
                getch();
                system("cls");
                AfficherSousMenuAdmin(AfficherMenuAdmin(option));
                break;
            case 3:
                GererSalleHoraire();
                printf("\n\t\tAppuyez sur une touche pour continuer");
                getch();
                system("cls");
                AfficherSousMenuAdmin(AfficherMenuAdmin(option));

                break;
            case 4:
                AfficherExams();
                printf("\n\t\tAppuyez sur une touche pour continuer");
                getch();
                system("cls");
                AfficherSousMenuAdmin(AfficherMenuAdmin(option));

                break;
            case 5:
                system("cls");
                printf("au revoir\n");
                return;
        }
    }
int AfficherMenuProffeseur() {
    time_t t;
    time(&t);
        int option;
    printf("\n\t\t\t\t                           %s", ctime(&t));
    printf("\t\t\t\t        --------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t        |\t\t 1) Consulter les examens attribuer                                     |\n");
    printf("\t\t\t\t        |\t\t 2) Quitter                                                             |\n");
    printf("\t\t\t\t        --------------------------------------------------------------------------------------\n");
    printf(" \t\t Entrez votre choix: ");
        scanf("%d", &option);
    system("cls");
        return option;
    }
void AfficherSousMenuProffeseur(int option , Prof p1) {

        switch (option) {


            case 1:
                printf("\n\n\n\n");
                printf("\t\t\t\t");
                printf("\n\n\n\n");

                printf("\t\t--------------------------------------------------------------------------------------\n");
                printf("        |\t\t\t\t 1) Consulter les exams a surveille                                             |\n");
                printf("        |\t\t\t\t 2) Consulter les exams a faire                                                 |\n");
                printf("        |\t\t\t\t 3) Quitter                                                                     |\n");

                printf("\t\t--------------------------------------------------------------------------------------\n");
                printf(" \t\t\t\t Entrez votre choix: ");
                scanf("%d", &option);
                system("cls");
                switch (option) {
                    case 1:
                        Consultesurveillance(p1);
                        printf("\n\t\tAppuyez sur une touche pour continuer");
                        getch();
                        system("cls");
                        AfficherSousMenuProffeseur(AfficherMenuProffeseur(),p1);
                        break;
                    case 2:
                        ConsulteExams(p1);
                        printf("\n\t\tAppuyez sur une touche pour continuer");
                        getch();
                        system("cls");
                        AfficherSousMenuProffeseur(AfficherMenuProffeseur(),p1);
                        break;
                    case 3:
                        exit(0);
                        break;
                }
                break;
            case 2:
                printf("\t\t\t\t\t\tAu revoir\n");
                exit(0);
                break;
        }
    }
int AfficherMenuEtudiant() {


        int option;
    time_t t;
    time(&t);
    printf("\n\n\n\n");
    printf("\t\t\t\t");
    printf("\n\n\n\n");
    printf("\n\t\t\t\t                           %s", ctime(&t));
    printf("        ----------------------------------------------------------------\n");
    printf("        |\t\t 1) Consulter le planing des examens         |\n");
    printf("        |\t\t 2) Quitter                                  |\n");
    printf("        ----------------------------------------------------------------\n");
    printf(" \t\t Entrez votre choix: ");
    scanf("%d", &option);
    system("cls");
        return option;
    }
void AfficherSousMenuEtudiant(etud e,int option) {
    switch (option) {
        case 1:
            printf("\t\t\t\t\tAffichage de votre examen\n");

            etud e1;
            Exam e2;
            Salles s;
            char salle[20];
            FILE *f = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Etud_Salle.txt", "rt");
            FILE *f1 = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Exam.txt", "rt");

            if (f == NULL || f1 == NULL) {
                perror("Erreur lors de l'ouverture du fichier");
                return;
            } else {
                while (fscanf(f, "%s %s %s %s %s %s %s %s %s", e1.cne, e1.nom, e1.prenom, e1.cycle, e1.filiére, e1.semestre, salle,s.AmphiBloc, s.salle) == 9) {
                    if (strcasecmp(e.cne, e1.cne) == 0) {
                        printf("Votre salle est %s %s\n", s.AmphiBloc, s.salle);
                        break;
                    }
                }

                rewind(f1);  // Remettre le curseur au début du fichier exam.txt

                while (fscanf(f1, "%s %s %s %s %s %s %s", e2.m.moduleName, e2.m.professor, e2.m.Cycle, e2.m.Filiére, e2.m.Semestre, e2.dat, e2.duree) == 7) {
                    if (strcasecmp(e.semestre, e2.m.Semestre) == 0) {
                        printf("Exam: %s %s %s %s %s %s %s\n", e2.m.moduleName, e2.m.professor, e2.m.Cycle, e2.m.Filiére, e2.m.Semestre, e2.dat, e2.duree);
                    }
                }
            }

            fclose(f);
            fclose(f1);
            printf("\n\t\tAppuyez sur une touche pour continuer");
            getch();
            exit(0);

            break;
        case 2:
            printf(" \t\t\t\t\t\t\t Au revoir\n");
            exit(0);
            break;
            }
}
void ConnexionProf(){
        Prof p, p1;
        utilisateur usr;
        printf("\n\n\n");
        printf("\t\t\t\t\t\tEmail : ");
        scanf("%s", p.Email);
        printf("\n\n");
        printf("\t\t\t\t\t\tMot de passe : ");
        scanf("%s", usr.mot_de_passe);
        system("cls");
        FILE *f = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Prof.txt", "rt");
        int connexionReussie = 0;  // Variable pour indiquer si la connexion est réussie
        while (fscanf(f, "%s %s %s", p1.Nom, p1.Prenom, p1.Email) == 3) {
            if (strcmp(p.Email, p1.Email) == 0 && strcmp(usr.mot_de_passe, "PROF") == 0) {
                connexionReussie = 1;  // Mettre la variable à 1 si la connexion réussie
                printf("\t\t\t\t\t------------------------------------------------------------- \t\t\t\n");
                printf("\t\t\t\t\t\t\t\tBienvenue %s %s\t\t\t\n", p1.Nom, p1.Prenom);

                AfficherSousMenuProffeseur(AfficherMenuProffeseur() , p1 );
                break;  // Sortir de la boucle une fois la connexion réussie
            } else{
                printf("\n\n\n");
                printf("\t\t\t\tEchec de Connexion Ereur dans Email ou Mot de passe");
                sleep(2);
                system("cls");
                ConnexionProf();
            }
        }
        fclose(f);

        if (!connexionReussie) {
            printf("echec de la connexion !\n");
        }

    }
void ConnexionEtud() {
    etud e1;
    etud e;
    utilisateur usr;
    char nom[20];
    char prenom[20];
    char semestre[20];
    char cycle[20];
    char Filiére[20];
    int connexionReussie = 0;

    printf("\n\n\n");
    printf("\t\t\t\t\t               Identifiant : ");
    scanf("%s",e1.cne);
    printf("\n\n");
    printf("\t\t\t\t\t               Mot de passe : ");
    scanf("%s", usr.mot_de_passe);
    system("cls");

    FILE *f = fopen("C:\\Users\\Iliass\\CLionProjects\\test\\Etud.txt", "rt");

    while (fscanf(f, "%s %s %s %s %s %s",e.cne,e.nom,e.prenom,e.cycle,e.filiére,e.semestre) == 6) {
        if (strcmp(e.cne, e1.cne) == 0 && strcmp(usr.mot_de_passe, "ETUD") == 0) {
            connexionReussie = 1;
            strcpy(nom,e.nom);
            strcpy(prenom,e.prenom);
            strcpy(cycle,e.cycle);
            strcpy(Filiére,e.filiére);
            strcpy(semestre,e.semestre);
            break;
        }
        else{
            printf("\n\n\n");
            printf("\t\t\t\tEchec de Connexion Ereur dans Identifiant ou Mot de passe");
            sleep(2);
            system("cls");
            ConnexionEtud();
        }
    }

    fclose(f);

    if (connexionReussie==1) {
        printf("\t\t\t\t\t\t\t\tBienvenue\t\t\t\t\n");
        printf("\t\t\t\t\t\t  %s %s Etudiant au %s En Filiere %s en semestre %s\t\t\t\t\n",nom,prenom,cycle,Filiére,semestre);
        AfficherSousMenuEtudiant(e,AfficherMenuEtudiant());
    } else {
        printf("echec de la connexion !\n");
    }
}
void ConnexionAdmin();
void ConnexionAdmin() {
    utilisateur usr;
    printf("\n\n\n");
    printf(" \t\t\t\t\t\t    Email : ");
    scanf("%s", usr.id);
    printf("\n\n");
    printf(" \t\t\t\t\t\t    Mot de passe : ");
    scanf("%s",usr.mot_de_passe);
    system("cls");
    if (strcmp(usr.id, "admin") == 0 && strcmp(usr.mot_de_passe, "admin") == 0) {
        printf("\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t Bienvenue\t\t\t\t\n");
        AfficherSousMenuAdmin(AfficherMenuAdmin());
    }
    else{
        printf("\n\n\n");
        printf("\n\n\t\t\t\t\tEchec de conexion !");
        sleep(2);
        system("cls");
        ConnexionAdmin();
    }
}
void connexion(utilisateur *usr) {
    time_t t;
    time(&t);
    printf("\n\t\t\t\t                           %s\n", ctime(&t));

    printf("\t\t\t\t         --------------------------------------------------\n");
    printf("\t\t\t\t        |\t\t 1) Administration               |\n");
    printf("\t\t\t\t        |\t\t 2) Professeur                   |\n");
    printf("\t\t\t\t        |\t\t 3) Etudiant                     |\n");
    printf("\t\t\t\t        |\t\t 4) Quitter                      |\n");
    printf("\t\t\t\t         -------------------------------------------------\n");


    printf("\n\n\n");
    printf(" \t\t\t\t                    Entrez votre type d'utilisateur: ");
    scanf("%d", &usr->type_utilisateur);
    system("cls");
    if (usr->type_utilisateur == 1 && strcmp(usr->id, "1") == 0 && strcmp(usr->mot_de_passe, "1") == 0) {
        printf("\t\t\t\t\t\t\tBienvenue\t\t\t\t\n");
        AfficherSousMenuAdmin(AfficherMenuAdmin());
    }

    if (usr->type_utilisateur == 4) {
        printf("Au revoir.\n");
        return;
    }
    if (usr->type_utilisateur == 2){
        ConnexionProf();
    }
    if (usr->type_utilisateur == 3){
        ConnexionEtud();
    }
    if (usr ->type_utilisateur == 1){
        ConnexionAdmin();
    }
    }
int main() {
    loading();
    system("cls");
    RemplireExam();
    utilisateur usr;
    setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY, BACKGROUND_BLUE);
    connexion(&usr);
    return 0;
}