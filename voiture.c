#include "voiture.h"
void afficherVoiture(Voiture voiture)
{
    printf("| %-3d | %-17s | %-17s | %-12s | %-10d | %-17s | %-12.2f | %-10s |\n",
           voiture.id, voiture.marque, voiture.modele, voiture.carburant,
           voiture.nbPlaces, voiture.transmission, voiture.prixJour,
           voiture.disponible ? "Oui" : "Non");
}

int chargerVoitures(const char* fichier, Voiture** voitures)
{
    FILE* file = fopen(fichier, "r");
    if (!file)
    {
        printf("Fichier introuvable. Creation d'une nouvelle liste de voitures.\n");
        *voitures = (Voiture*)malloc(10 * sizeof(Voiture));
        return 0;
    }

    int max_voitures = 10;
    int nb_voitures = 0;

    *voitures = (Voiture*)malloc(max_voitures * sizeof(Voiture));
    if (!(*voitures))
    {
        perror("Erreur d'allocation memoire");
        fclose(file);
        return 0;
    }

    while (fscanf(file, "%d,%49[^,],%49[^,],%19[^,],%d,%19[^,],%lf,%d\n",
                  &(*voitures)[nb_voitures].id, (*voitures)[nb_voitures].marque,
                  (*voitures)[nb_voitures].modele, (*voitures)[nb_voitures].carburant,
                  &(*voitures)[nb_voitures].nbPlaces, (*voitures)[nb_voitures].transmission,
                  &(*voitures)[nb_voitures].prixJour, &(*voitures)[nb_voitures].disponible) == 8)
    {
        nb_voitures++;

        if (nb_voitures == max_voitures)
        {
            max_voitures *= 2;
            *voitures = (Voiture*)realloc(*voitures, max_voitures * sizeof(Voiture));
            if (!(*voitures))
            {
                perror("Erreur de reallocation memoire");
                fclose(file);
                return nb_voitures;
            }
        }
    }

    fclose(file);
    return nb_voitures;
}
void sauvegarderVoitures(Voiture* voitures, int nb_voitures, const char* fichier)
{
    FILE* file = fopen(fichier, "w");
    if (!file)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    for (int i = 0; i < nb_voitures; i++)
    {
        fprintf(file, "%d,%s,%s,%s,%d,%s,%.2f,%d\n",
                voitures[i].id, voitures[i].marque, voitures[i].modele, voitures[i].carburant,
                voitures[i].nbPlaces, voitures[i].transmission, voitures[i].prixJour,
                voitures[i].disponible);
    }

    fclose(file);
}

void ajouterVoiture(Voiture** voitures, int* nb_voitures, int* max_voitures)
{
    if (*nb_voitures == *max_voitures)
    {
        *max_voitures *= 2;
        *voitures = (Voiture*)realloc(*voitures, *max_voitures * sizeof(Voiture));
        if (!(*voitures))
        {
            perror("Erreur de r�allocation memoire");
            return;
        }
    }

    Voiture nouvelle;
    printf("ID: ");
    scanf("%d", &nouvelle.id);
    printf("Marque: ");
    scanf(" %49[^\n]", nouvelle.marque);
    printf("Modele: ");
    scanf(" %49[^\n]", nouvelle.modele);
    printf("Carburant: ");
    scanf(" %19[^\n]", nouvelle.carburant);
    printf("Nombre de places: ");
    scanf("%d", &nouvelle.nbPlaces);
    printf("Transmission (automatique/manuelle): ");
    scanf(" %19[^\n]", nouvelle.transmission);
    printf("Prix par jour: ");
    scanf("%lf", &nouvelle.prixJour);
    printf("Disponible (1 pour oui, 0 pour non): ");
    scanf("%d", &nouvelle.disponible);

    (*voitures)[*nb_voitures] = nouvelle;
    (*nb_voitures)++;
    printf("Voiture ajoutee avec succes.\n");
}

void modifierVoiture(Voiture* voitures, int nb_voitures)
{
    int id, trouve = 0;
    printf("Entrez l'ID de la voiture � modifier: ");
    scanf("%d", &id);

    for (int i = 0; i < nb_voitures; i++)
    {
        if (voitures[i].id == id)
        {
            trouve = 1;
            printf("Modification de la voiture (ID: %d):\n", id);
            printf("Nouvelle marque (actuelle: %s): ", voitures[i].marque);
            scanf(" %49[^\n]", voitures[i].marque);
            printf("Nouveau modele (actuel: %s): ", voitures[i].modele);
            scanf(" %49[^\n]", voitures[i].modele);
            printf("Nouveau carburant (actuel: %s): ", voitures[i].carburant);
            scanf(" %19[^\n]", voitures[i].carburant);
            printf("Nouveau nombre de places (actuel: %d): ", voitures[i].nbPlaces);
            scanf("%d", &voitures[i].nbPlaces);
            printf("Nouvelle transmission (actuelle: %s): ", voitures[i].transmission);
            scanf(" %19[^\n]", voitures[i].transmission);
            printf("Nouveau prix par jour (actuel: %.2f): ", voitures[i].prixJour);
            scanf("%lf", &voitures[i].prixJour);
            printf("Disponible (actuel: %d): ", voitures[i].disponible);
            scanf("%d", &voitures[i].disponible);
            printf("Voiture modifi�e avec succes.\n");
            break;
        }
    }

    if (!trouve)
    {
        printf("Voiture avec ID %d non trouvee.\n", id);
    }
}

void supprimerVoiture(Voiture* voitures, int* nb_voitures)
{
    int id, trouve = 0;
    printf("Entrez l'ID de la voiture � supprimer: ");
    scanf("%d", &id);

    for (int i = 0; i < *nb_voitures; i++)
    {
        if (voitures[i].id == id)
        {
            trouve = 1;
            for (int j = i; j < *nb_voitures - 1; j++)
            {
                voitures[j] = voitures[j + 1];
            }
            (*nb_voitures)--;
            printf("Voiture supprimee avec succes.\n");
            break;
        }
    }

    if (!trouve)
    {
        printf("Voiture avec ID %d non trouvee.\n", id);
    }
}

void rechercherVoiture(Voiture* voitures, int nb_voitures)
{
    int choix;
    printf("Rechercher par:\n");
    printf("1. Marque\n");
    printf("2. Disponibilite\n");
    printf("Votre choix: ");
    scanf("%d", &choix);

    if (choix == 1)
    {
        char marque[50];
        printf("Entrez la marque: ");
        scanf(" %49[^\n]", marque);
        printf("%-5s%-15s%-15s%-10s%-10s%-15s%-10s%-10s\n",
               "ID", "Marque", "Modele", "Carburant", "Places", "Transmission", "Prix/J", "Dispo");
        for (int i = 0; i < nb_voitures; i++)
        {
            if (strcmp(voitures[i].marque, marque) == 0)
            {
                afficherVoiture(voitures[i]);
            }
        }
    }
    else if (choix == 2)
    {
        int dispo;
        printf("Entrez 1 pour disponible, 0 pour non disponible: ");
        scanf("%d", &dispo);
        printf("%-5s%-15s%-15s%-10s%-10s%-15s%-10s%-10s\n",
               "ID", "Marque", "Modele", "Carburant", "Places", "Transmission", "Prix/J", "Dispo");
        for (int i = 0; i < nb_voitures; i++)
        {
            if (voitures[i].disponible == dispo)
            {
                afficherVoiture(voitures[i]);
            }
        }
    }
    else
    {
        printf("Choix invalide.\n");
    }
}

int comparerParMarque(const void* a, const void* b)
{
    return strcmp(((Voiture*)a)->marque, ((Voiture*)b)->marque);
}

int comparerParPrix(const void* a, const void* b)
{
    double diff = ((Voiture*)a)->prixJour - ((Voiture*)b)->prixJour;
    return (diff > 0) - (diff < 0);
}
void trierVoitures(Voiture* voitures, int nb_voitures)
{
    int choix;
    printf("Trier par:\n");
    printf("1. Marque\n");
    printf("2. Prix de location par jour\n");
    printf("Votre choix: ");
    scanf("%d", &choix);

    if (choix == 1)
    {
        qsort(voitures, nb_voitures, sizeof(Voiture), comparerParMarque);
        printf("Voitures triees par marque.\n");
    }
    else if (choix == 2)
    {
        qsort(voitures, nb_voitures, sizeof(Voiture), comparerParPrix);
        printf("Voitures triees par prix de location.\n");
    }
    else
    {
        printf("Choix invalide.\n");
    }
}
