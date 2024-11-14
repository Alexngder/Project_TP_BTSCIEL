<?php
if (isset($_POST['Nombre1']) && isset($_POST['Operation']) && isset($_POST['Nombre2'])) {
    $n1 = $_POST['Nombre1'];
    $op = $_POST['Operation'];
    $n2 = $_POST['Nombre2'];

    echo "Résultat du calcul " . $n1 . " " . $op . " " . $n2 . " : ";

    if ($op == "+") {
        echo $n1 + $n2;
    } elseif ($op == "-") {
        echo $n1 - $n2;
    } elseif ($op == "*") {
        echo $n1 * $n2;
    } elseif ($op == "/") {
        if ($n2 != 0) {
            echo $n1 / $n2;
        } else {
            echo "Erreur : Division par zéro.";
        }
    }
}   
?>