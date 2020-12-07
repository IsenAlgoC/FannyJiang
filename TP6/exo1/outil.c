#include <stdio.h>   /* pour les entrées-sorties */
#include <string.h>  /* pour les manipulations de chaînes de caractères */
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include "rep.h"

#define VERSION 3.0
#define SQUELET
/**************************************************************************/
/* Compléter votre nom ici                                                */
/*   Nom :JIANG                 Prénom : Fanny                            */
/**************************************************************************/

extern bool modif;


/**********************************************************************/
/*  Ajout d'un contact dans le répertoire stocké en mémoire           */
/**********************************************************************/

int ajouter_un_contact_dans_rep(Repertoire* rep, Enregistrement enr)
{
#ifdef IMPL_TAB
	// compléter code ici pour tableau
	int idx = rep->nb_elts;

	if (rep->nb_elts < MAX_ENREG)
	{
		rep->tab[idx] = enr;
		rep->nb_elts += 1;
	}
	else {
		return(ERROR);
	}


#else
#ifdef IMPL_LIST

	bool inserted = false;
	if (rep->nb_elts == 0) {
		if (InsertElementAt(rep->liste, rep->liste->size, enr) != 0) {
			rep->nb_elts += 1;
			modif = true;
			rep->est_trie = true;
			return(OK);
		}

	}
	else {
		//
		// compléter code ici pour Liste
		//
		//
		//

	}


#endif

#endif


	return(OK);

} /* fin ajout */
  /**********************************************************************/
  /* supprime du répertoire l'enregistrement dont l'indice est donné en */
  /*   paramètre       et place modif = true                            */
  /**********************************************************************/
#ifdef IMPL_TAB
void supprimer_un_contact_dans_rep(Repertoire* rep, int indice) {

	// compléter code ici pour tableau
	if (rep->nb_elts >= 1) {                 /* s'il y a au moins un element ds le tableau */
		if (-1 < indice <= rep->nb_elts)		 /* et que l'indice pointe a l'interieur */
		{
			for (int i = indice; i < rep->nb_elts - 1; i++)
			{
				rep->tab[i] = rep->tab[i + 1];
			}
			rep->nb_elts -= 1;		/* ds ts les cas, il y a un element en moins */
			modif = true;
		}
		else {
			modif = false;
		}
	}

	return;
} /* fin supprimer */

#else
#ifdef IMPL_LIST
  /************************************************************************/
  /* supprime du répertoire l'enregistrement contenu dans le maillon elem */
  /*                   et fixe modif à vrai                              */
  /************************************************************************/
  // complet

int supprimer_un_contact_dans_rep_liste(Repertoire* rep, SingleLinkedListElem* elem) {

	int ret = DeleteLinkedListElem(rep->liste, elem);
	if (ret == 1) {
		rep->nb_elts--;
		modif = true;
	}

	return (0);
}
#endif
#endif


/**********************************************************************/
/*  fonction d'affichage d'un enregistrement sur une ligne à l'écran  */
/* ex Dupont, Jean                 0320304050                         */
/**********************************************************************/
void affichage_enreg(Enregistrement enr)
{
	// code à compléter ici

	printf("%s, %s                %s", enr.nom, enr.prenom, enr.tel);


} /* fin affichage_enreg */
  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement avec alignement des mots */
  /* pour les listes                                                    */
  /* ex | Dupont                |Jean                  |0320304050      */
  /**********************************************************************/
void affichage_enreg_frmt(Enregistrement enr)
{
	// code à compléter ici
	// comme fonction affichage_enreg, mais avec présentation alignées des infos
	printf_s("|%s", enr.nom);
	for (int i = strlen(enr.nom); i < MAX_NOM; i++) {
		printf_s(" ");
	}
	printf_s("|%s", enr.prenom);
	for (int i = strlen(enr.prenom); i < MAX_NOM; i++) {
		printf_s(" ");
	}
	printf_s("|%s", enr.tel);
	for (int i = strlen(enr.tel); i < MAX_TEL; i++) {
		printf_s(" ");
	}
	printf_s("\n");

} /* fin affichage_enreg */


  /**********************************************************************/
  /* test si dans l'ordre alphabetique, un enregistrement est apres     */
  /* un autre                                                           */
  /**********************************************************************/
bool est_sup(Enregistrement enr1, Enregistrement enr2) {
	// code à compléter ici

	if (strcoll(enr1.nom, enr2.nom) < 0) {    // si enr1<enr2 alors return val neg sinon positif et si egaux alors return 0 
		return (true);
	}
	else {
		if (strcoll(enr1.nom, enr2.nom) == 0) {
			if (strcoll(enr1.prenom, enr2.prenom) < 0) {
				return(true);
			}
			else {
				if (strcoll(enr1.prenom, enr2.prenom) == 0) {
					if (strcoll(enr1.tel, enr2.tel) < 0) {
						return(true);
					}
					else {
						return(true);
					}
				}
				else {
					return(false);
				}
			}
		}
		else {
			return(false);
		}
	}

}

/*********************************************************************/
/*   Tri Alphabetique du tableau d'enregistrements                   */
/*********************************************************************/

void trier(Repertoire* rep)
{

#ifdef IMPL_TAB
	// ajouter code ici pour tableau
	for (int i = 0; i < rep->nb_elts - 1; i++) {
		for (int j = 0; j < rep->nb_elts - i - 1; j++) {
			if (est_sup(rep->tab[j + 1], rep->tab[j])) {
				Enregistrement tmp;
				tmp = rep->tab[j];
				rep->tab[j] = rep->tab[j + 1];
				rep->tab[j + 1] = tmp;
			}
		}
	}

#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
	// rien à faire !
	// la liste est toujours triée
#endif
#endif

	rep->est_trie = true;

} /* fin trier */

  /**********************************************************************/
  /* recherche dans le répertoire d'un enregistrement correspondant au  */
  /*   nom à partir de l'indice ind                                     */
  /*   retourne l'indice de l'enregistrement correspondant au critère ou*/
  /*   un entier négatif si la recherche est négative				    */
  /**********************************************************************/

int rechercher_nom(Repertoire* rep, char nom[], int ind)
{
	int i = ind;		    /* position (indice) de début de recherche dans tableau/liste rep */
	int ind_fin = rep->nb_elts;			/* position (indice) de fin de tableau/liste rep */

	char tmp_nom[MAX_NOM];	/* 2 variables temporaires dans lesquelles */
	char tmp_nom2[MAX_NOM];	/* on place la chaine recherchee et la chaine lue dans le */
							/* tableau, afin de les convertir en majuscules et les comparer */
	bool trouve = false;


#ifdef IMPL_TAB
	// ajouter code ici pour tableau
	strncpy_s(tmp_nom, _countof(tmp_nom), nom, _TRUNCATE);
	for (int j = 0; j < strlen(tmp_nom); j++) {
		*(tmp_nom + j) = toupper(*(tmp_nom + j));
	}

	while ((!trouve) && (i <= ind_fin)) {

		strncpy_s(tmp_nom2, _countof(tmp_nom), rep->tab[i].nom, _TRUNCATE);

		for (int k = 0; k < strlen(tmp_nom2); k++) {
			*(tmp_nom2 + k) = toupper(*(tmp_nom2 + k));
		}
		if (strcmp(tmp_nom2, tmp_nom) == 0) {
			trouve = true;
		}
		i += 1;
	}

#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste

#endif
#endif

	return((trouve) ? (i - 1) : -1);
} /* fin rechercher_nom */

  /*********************************************************************/
  /* Supprimer tous les caracteres non numériques de la chaines        */
  /*********************************************************************/
void compact(char* s)
{
	int p = 0;          // position dans le tableau
	int n = 0;			//le nombre de caractere non numerique
	for (int i = 0; i < strlen(s) + n; i++) {
		if (isdigit(s[p]) == 0) {
			for (int j = p; j < strlen(s); j++) {
				s[j] = s[j + 1];
				n++;
			}
		}
		else {
			p++;
		}
	}
	return;
}

/**********************************************************************/
/* sauvegarde le répertoire dans le fichier dont le nom est passé en  */
/* argument                                                           */
/* retourne OK si la sauvegarde a fonctionné ou ERROR sinon           */
/**********************************************************************/
int sauvegarder(Repertoire* rep, char nom_fichier[])
{
	FILE* fic_rep;					/* le fichier */
#ifdef IMPL_TAB
	// ajouter code ici pour tableau
	errno_t err;
	err = fopen_s(&fic_rep, nom_fichier, 'w');
	if ((fic_rep == NULL) || err != 0) {
		return ERROR;
	}
	else {
		for (int i = 0; i < rep->nb_elts; i++) {
			fprintf(fic_rep, "%s", rep->tab[i].nom);
			fprintf(fic_rep, "%s", rep->tab[i].prenom);
			fprintf(fic_rep, "%s\n", rep->tab[i].tel);
		}

	}
	fclose(fic_rep);

#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
#endif
#endif

	return(OK);
} /* fin sauvegarder */


  /**********************************************************************/
  /*   charge dans le répertoire le contenu du fichier dont le nom est  */
  /*   passé en argument                                                */
  /*   retourne OK si le chargement a fonctionné et ERROR sinon         */
  /**********************************************************************/

int charger(Repertoire* rep, char nom_fichier[])
{
	FILE* fic_rep;					/* le fichier */
	errno_t err;
	int num_rec = 0;						/* index sur enregistrements */
	int long_max_rec = sizeof(Enregistrement);
	char buffer[sizeof(Enregistrement) + 1];
	int idx = 0;

	char* char_nw_line;

	_set_errno(0);
	if (((err = fopen_s(&fic_rep, nom_fichier, "r")) != 0) || (fic_rep == NULL))
	{
		return(err);
	}
	else
	{
		while (!feof(fic_rep) && (rep->nb_elts < MAX_ENREG))
		{
			if (fgets(buffer, long_max_rec, fic_rep) != NULL)
			{
				/* memorisation de l'enregistrement lu dans le tableau */
				buffer[long_max_rec] = 0;			/* en principe il y a deja un fin_de_chaine, cf fgets */

				if ((char_nw_line = strchr(buffer, '\n')) != NULL)
					*char_nw_line = '\0';			/* suppression du fin_de_ligne eventuel */

				idx = 0;								/* analyse depuis le debut de la ligne */
#ifdef IMPL_TAB
				if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element à priori correct, on le comptabilise */
					}
				}
#else
#ifdef IMPL_LIST
														// ajouter code implemention liste
#endif
#endif




			}

		}
		rep->nb_elts = num_rec;
		fclose(fic_rep);
		return(OK);
	}


} /* fin charger */