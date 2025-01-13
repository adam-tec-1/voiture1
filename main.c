#include "voiture.h"

int main() {
    char utilisateur[50];
    printf("Entrez votre nom pour commencer: ");
    scanf(" %49[^\n]", utilisateur);

    printf("Bienvenue, %s!\n", utilisateur);

    Voiture* voitures;
    int max_voitures = 10;
    int nb_voitures = chargerVoitures("voitures.csv", &voitures);

    int choix;
    int afficherEntete = 1;
    do {
        printf("\nMenu:\n");
        printf("1. Afficher les voitures disponibles\n");
        printf("2. Ajouter une voiture\n");
        printf("3. Modifier une voiture\n");
        printf("4. Supprimer une voiture\n");
        printf("5. Rechercher une voiture\n");
        printf("6. Trier les voitures\n");
        printf("7. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("+-----+-------------------+-------------------+--------------+------------+-------------------+--------------+------------+\n");
                printf("| ID  | Marque            | Modele            | Carburant    | Places     | Transmission      | Prix/J       | Dispo      |\n");
                printf("+-----+-------------------+-------------------+--------------+------------+-------------------+--------------+------------+\n");
                for (int i = 0; i < nb_voitures; i++) {
                    if (voitures[i].disponible) {
                        afficherVoiture(voitures[i]);
                    }
                }
                break;

            case 2:
                ajouterVoiture(&voitures, &nb_voitures, &max_voitures);
                break;

            case 3:
                modifierVoiture(voitures, nb_voitures);
                break;

            case 4:
                supprimerVoiture(voitures, &nb_voitures);
                break;

            case 5:
                rechercherVoiture(voitures, nb_voitures);
                break;

            case 6:
                trierVoitures(voitures, nb_voitures);
                break;

            case 7:
                sauvegarderVoitures(voitures, nb_voitures, "voitures.csv");
                printf("Données sauvegardees. Au revoir!\n");
                break;

            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 7);

    free(voitures);
    return 0;
}
