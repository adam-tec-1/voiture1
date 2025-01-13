#ifndef VOITURE_H
#define VOITURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char marque[50];
    char modele[50];
    char carburant[20];
    int nbPlaces;
    char transmission[20];
    double prixJour;
    int disponible;
} Voiture;

void afficherVoiture(Voiture voiture);
int chargerVoitures(const char* fichier, Voiture** voitures);
void sauvegarderVoitures(Voiture* voitures, int nb_voitures, const char* fichier);
void ajouterVoiture(Voiture** voitures, int* nb_voitures, int* max_voitures);
void modifierVoiture(Voiture* voitures, int nb_voitures);
void supprimerVoiture(Voiture* voitures, int* nb_voitures);
void rechercherVoiture(Voiture* voitures, int nb_voitures);
void trierVoitures(Voiture* voitures, int nb_voitures);

#endif

