Exercice 1 :INF 231 : Suppression des occurrences dans une liste simplement chaînée

1. Problème :
Écrire un programme en langage C qui :
● Lit les éléments d’une liste simplement chaînée.
● Lit une valeur x entrée par l’utilisateur.
● Supprime toutes les occurrences de x dans la liste.
● Affiche la liste après suppression.

2. Principe :
● On crée une liste simplement chaînée avec les éléments saisis.
● On parcourt la liste pour trouver toutes les occurrences de la valeur x.
● Chaque occurrence est supprimée.
● Si x n’existe pas dans la liste, on affiche un message.
● Si x existe, on affiche la liste mise à jour après suppression.

3. Dictionnaire de données :
● Node : structure représentant un nœud de la liste, avec :
● valeur : entier stocké dans le nœud.
● suiv : pointeur vers le nœud suivant.

● liste : pointeur vers le premier nœud de la liste.

● n : nombre d’éléments saisis par l’utilisateur.
● val : valeur saisie pour chaque nœud.
● x : valeur à supprimer dans la liste.
● trouve : variable indicatrice (1 si la valeur est trouvée, 0 sinon).

4. Algorithme :
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
typedef struct Node {
int valeur;
struct Node *suiv;
} Node;
Node* nouveau_node(int v) {
Node* p = (Node*) malloc(sizeof(Node));
if (p == NULL) exit(1);
p-&gt;valeur = v;
p-&gt;suiv = NULL;
return p;
}
Node* inserer_fin(Node* tete, int v) {
Node* p = nouveau_node(v);
if (tete == NULL) return p;
Node* q = tete;
while (q-&gt;suiv != NULL) q = q-&gt;suiv;
q-&gt;suiv = p;
return tete;
}
void afficher(Node* tete) {
Node* p = tete;
while (p != NULL) {
printf(&quot;%d -&gt; &quot;, p-&gt;valeur);
p = p-&gt;suiv;

}
printf(&quot;NULL\n&quot;);
}
Node* supprimer_occurrences(Node* tete, int x, int* trouve) {
*trouve = 0;
while (tete != NULL &amp;&amp; tete-&gt;valeur == x) {
Node* tmp = tete;
tete = tete-&gt;suiv;
free(tmp);
*trouve = 1;
}
Node* courant = tete;
while (courant != NULL &amp;&amp; courant-&gt;suiv != NULL) {
if (courant-&gt;suiv-&gt;valeur == x) {
Node* tmp = courant-&gt;suiv;
courant-&gt;suiv = courant-&gt;suiv-&gt;suiv;
free(tmp);
*trouve = 1;
} else {
courant = courant-&gt;suiv;
}
}
return tete;
}
int main() {
Node* liste = NULL;
int n, i, val, x, trouve;
printf(&quot;\n== Suppression des occurrences dans une liste chaînée ==\n\n&quot;);
printf(&quot;Entrez le nombre d’elements : &quot;);
scanf(&quot;%d&quot;, &amp;n);
for (i = 0; i &lt; n; i++) {
printf(&quot;Entrez l’element %d : &quot;, i + 1);
scanf(&quot;%d&quot;, &amp;val);
liste = inserer_fin(liste, val);
}
printf(&quot;\nListe initiale : &quot;);

afficher(liste);
printf(&quot;Entrez la valeur à supprimer : &quot;);
scanf(&quot;%d&quot;, &amp;x);
liste = supprimer_occurrences(liste, x, &amp;trouve);
if (trouve) {
printf(&quot;\nListe après suppression : &quot;);
afficher(liste);
} else {
printf(&quot;\nLa valeur %d n’existe pas dans la liste.\n&quot;, x);
}
return 0;
}

5.Traces d’exécution et vérifications

● Cas 1 : Valeur présente une seule fois
Entrées :
Liste : 1 -&gt; 4 -&gt; 6 -&gt; 8
Valeur à supprimer : 6

● Trace d’exécution :

Liste initiale : 1 -&gt; 4 -&gt; 6 -&gt; 8 -&gt; NULL
Entrez la valeur à supprimer : 6
Liste après suppression : 1 -&gt; 4 -&gt; 8 -&gt; NULL

● Vérification :

6 trouvé à la troisième position → supprimé
Les autres éléments restent inchangés
● Résultat correct.

● Cas 2 : Valeur présente plusieurs fois
Entrées :
Liste : 3 -&gt; 7 -&gt; 2 -&gt; 7 -&gt; 9
Valeur à supprimer : 7

● Trace d’exécution :

Liste initiale : 3 -&gt; 7 -&gt; 2 -&gt; 7 -&gt; 9 -&gt; NULL
Entrez la valeur à supprimer : 7
Liste après suppression : 3 -&gt; 2 -&gt; 9 -&gt; NULL

● Vérification :

Premier 7 trouvé → supprimé → 3 -&gt; 2 -&gt; 7 -&gt; 9
Deuxième 7 trouvé → supprimé → 3 -&gt; 2 -&gt; 9
● Résultat correct.

● Cas 3 : Valeur absente
Entrées :
Liste : 2 -&gt; 5 -&gt; 7 -&gt; 9
Valeur à supprimer : 4

● Trace d’exécution :

Liste initiale : 2 -&gt; 5 -&gt; 7 -&gt; 9 -&gt; NULL
Entrez la valeur à supprimer : 4
La valeur 4 n’existe pas dans la liste.

● Vérification:
4 n’apparaît pas dans la liste
La liste reste inchangée → 2 -&gt; 5 -&gt; 7 -&gt; 9 -&gt; NULL
● Résultat correct.

7. Complexité :
Temps : O(n)
Chaque nœud est visité au maximum une fois pour suppression.

Espace : O(n)
nœuds stockés dans la liste + mémoire temporaire pour suppression.