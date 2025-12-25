#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Structure pour le retour de la fonction récursive
typedef struct {
    int valeur;
    int position_fin;
    int erreur; // 0 si OK, 1 si erreur
} Resultat;

// --- CHECKPOINT 1 : prochain_espace ---
int prochain_espace(const char* s, int pos) {
    while (s[pos] != '\0' && s[pos] != ' ' && s[pos] != '\n' && s[pos] != '\r') {
        pos++;
    }
    return pos;
}

// --- CHECKPOINT 2 & 4 : calcule_aux avec gestion d'erreurs ---
Resultat calcule_aux(const char* s, int pos) {
    // Sauter les espaces
    while (s[pos] == ' ') pos++;

    // Si on atteint la fin de la chaîne de manière inattendue
    if (s[pos] == '\0' || s[pos] == '\n' || s[pos] == '\r') {
        return (Resultat){0, pos, 1}; 
    }

    int fin = prochain_espace(s, pos);
    int len = fin - pos;
    char token[64];
    strncpy(token, s + pos, len);
    token[len] = '\0';

    Resultat res = {0, fin, 0};

    // Vérifier si c'est un opérateur
    if (strcmp(token, "+") == 0 || strcmp(token, "*") == 0) {
        char op = token[0];
        
        Resultat gauche = calcule_aux(s, fin);
        if (gauche.erreur) return gauche;

        Resultat droite = calcule_aux(s, gauche.position_fin);
        if (droite.erreur) return droite;

        if (op == '+') res.valeur = gauche.valeur + droite.valeur;
        else res.valeur = gauche.valeur * droite.valeur;
        
        res.position_fin = droite.position_fin;
    } 
    else {
        // Vérifier si le jeton est bien un nombre
        for (int i = 0; i < len; i++) {
            if (!isdigit(token[i]) && !(i == 0 && token[i] == '-')) {
                res.erreur = 1;
                return res;
            }
        }
        res.valeur = atoi(token);
    }
    return res;
}

// --- SECTION 2.1 : Génération aléatoire ---
// Génère une chaîne "+ A B" telle que A + B = resultat
char* addition_valant(int resultat) {
    if (resultat == 0) {
        char* s = malloc(10);
        strcpy(s, "+ 0 0");
        return s;
    }
    int a = rand() % (abs(resultat) + 1);
    int b = resultat - a;
    
    char* str = malloc(50);
    sprintf(str, "+ %d %d", a, b);
    return str;
}

// --- CHECKPOINT 3 : listen ---
void listen() {
    char buffer[1024];
    printf("--- Mini Calculatrice Polonaise ---\n");
    printf("Commandes : '+ 3 4', '* + 1 2 3', ou tapez 'gen <n>' pour generer une addition.\n");

    while (1) {
        printf("> ");
        if (!fgets(buffer, sizeof(buffer), stdin)) break;
        if (buffer[0] == '\n') continue;

        // Commande spéciale pour la génération
        if (strncmp(buffer, "gen ", 4) == 0) {
            int cible = atoi(buffer + 4);
            char* expr = addition_valant(cible);
            printf("Expression generee : %s\n", expr);
            free(expr);
            continue;
        }

        Resultat r = calcule_aux(buffer, 0);
        
        if (r.erreur) {
            printf("Erreur : Expression mal formee.\n");
        } else {
            printf("Resultat : %d\n", r.valeur);
        }
    }
}

int main() {
    srand(time(NULL)); // Initialisation de l'aléatoire
    listen();
    return 0;
}
