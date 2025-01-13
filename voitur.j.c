/*# Gestion des Voitures - Description des Fonctionnalités

Ce document décrit la fonctionnalité de chaque fonction utilisée dans le programme de gestion des voitures.

---

## Aperçu des Fichiers

1. **main.c**
   - Point d'entrée du programme.
   - Gère l'interaction avec l'utilisateur et les choix de menu.
   - Appelle les fonctions de `voiture.c` pour effectuer les différentes opérations.

2. **voiture.h**
   - Contient la définition de la structure `Voiture` et les prototypes des fonctions.

3. **voiture.c**
   - Implémente toutes les fonctionnalités principales liées à la structure `Voiture`.

---

## Description des Fonctions

### 1. `afficherVoiture(Voiture voiture)`
**But :**
Affiche les détails d'une voiture dans un format tabulaire.

**Paramètres :**
- `Voiture voiture` : La voiture à afficher.

**Valeur de retour :**
Aucune.

---

### 2. `int chargerVoitures(const char* fichier, Voiture** voitures)`
**But :**
Charge les voitures à partir d'un fichier CSV en mémoire.

**Paramètres :**
- `const char* fichier` : Le nom du fichier à partir duquel charger les voitures.
- `Voiture** voitures` : Un pointeur vers le tableau des voitures.

**Valeur de retour :**
- Le nombre de voitures chargées en mémoire.

---

### 3. `void sauvegarderVoitures(Voiture* voitures, int nb_voitures, const char* fichier)`
**But :**
Sauvegarde la liste actuelle des voitures dans un fichier CSV.

**Paramètres :**
- `Voiture* voitures` : Le tableau des voitures.
- `int nb_voitures` : Le nombre de voitures à sauvegarder.
- `const char* fichier` : Le nom du fichier où sauvegarder les voitures.

**Valeur de retour :**
Aucune.

---

### 4. `void ajouterVoiture(Voiture** voitures, int* nb_voitures, int* max_voitures)`
**But :**
Ajoute une nouvelle voiture à la liste.

**Paramètres :**
- `Voiture** voitures` : Un pointeur vers le tableau des voitures.
- `int* nb_voitures` : Un pointeur vers le nombre de voitures.
- `int* max_voitures` : Un pointeur vers la capacité maximale du tableau.

**Valeur de retour :**
Aucune.

---

### 5. `void modifierVoiture(Voiture* voitures, int nb_voitures)`
**But :**
Modifie les détails d'une voiture existante.

**Paramètres :**
- `Voiture* voitures` : Le tableau des voitures.
- `int nb_voitures` : Le nombre total de voitures.

**Valeur de retour :**
Aucune.

---

### 6. `void supprimerVoiture(Voiture* voitures, int* nb_voitures)`
**But :**
Supprime une voiture identifiée par son ID.

**Paramètres :**
- `Voiture* voitures` : Le tableau des voitures.
- `int* nb_voitures` : Un pointeur vers le nombre total de voitures.

**Valeur de retour :**
Aucune.

---

### 7. `void rechercherVoiture(Voiture* voitures, int nb_voitures)`
**But :**
Permet de rechercher une voiture par marque ou disponibilité.

**Paramètres :**
- `Voiture* voitures` : Le tableau des voitures.
- `int nb_voitures` : Le nombre total de voitures.

**Valeur de retour :**
Aucune.

---

### 8. `void trierVoitures(Voiture* voitures, int nb_voitures)`
**But :**
Trie les voitures par marque ou par prix de location par jour.

**Paramètres :**
- `Voiture* voitures` : Le tableau des voitures.
- `int nb_voitures` : Le nombre total de voitures.

**Valeur de retour :**
Aucune.

---

### 9. `int comparerParMarque(const void* a, const void* b)`
**But :**
Compare deux voitures en fonction de leur marque pour le tri.

**Paramètres :**
- `const void* a` : Première voiture.
- `const void* b` : Deuxième voiture.

**Valeur de retour :**
Un entier indiquant l'ordre.

---

### 10. `int comparerParPrix(const void* a, const void* b)`
**But :**
Compare deux voitures en fonction de leur prix de location pour le tri.

**Paramètres :**
- `const void* a` : Première voiture.
- `const void* b` : Deuxième voiture.

**Valeur de retour :**
Un entier indiquant l'ordre.

---

Fin de la description.
*/
