<?php
if (isset($_POST['taille']) && isset($_POST['poids'])) {
    $taille = $_POST['taille'];
    $poids = $_POST['poids'];
    $taillenbr = $taille*$taille;
    $resultat = $poids /$taillenbr;
    echo "Résultat du calcul de l'IMC : ";
    echo nl2br($resultat . "\n");

    echo nl2br("\nTableau d'IMC" . "\n");
    echo nl2br("moins de 18,5 -> Insuffisance pondérale (maigreur)" . "\n");
    echo nl2br("18,5 à 25 -> Corpulence normale" . "\n");
    echo nl2br("25 à 30 -> Surpoids" . "\n");
    echo nl2br("30 à 35 -> Obésité modérée" . "\n");
    echo nl2br("35 à 40 -> Obésité sévère" . "\n");
    echo nl2br("plus de 40 -> Obésité morbide ou massive" . "\n"); 
}   
?>