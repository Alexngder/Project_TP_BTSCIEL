<?php
$tableau = array("login"=>"1234", "root"=>"root", "Admin"=>"mot de passe","test"=>"test", "Alex"=>"Alex2024btsciel@2", "Azerty"=>"azerty");
if (isset($_POST['login']) && isset($_POST['password'])) {
    $login = $_POST['login'];
    $password = $_POST['password'];
    $flag = false;

    foreach ($tableau as $session => $mdp){
        if ($login == $session && $password == $mdp){
            echo"Bienvenue";
            $flag= true;
            break;   
        }
    }    
}   
if ($flag ==false) {
    echo "<style>
    table {
    font-family: arial, sans-serif;
    border-collapse: collapse;
    width: 100%;
    }

    td, th {
    border: 1px solid #dddddd;
    text-align: left;
    padding: 8px;
    }

    tr:nth-child(even) {
    background-color: #dddddd;
    }
    </style>";

    echo"<h1>Non Acces</h1>";
    echo"<h2>Tbleau de password</h2>";
    echo "<Table>
    <tr>
    <th>Identifiant</th>
    <th>Mot de passe</th>
    </tr>";
    foreach ($tableau as $session => $mdp){
        echo "
        <tr>
        <td>$session</td>
        <td>$mdp</td>
        </tr>";
    }
    echo"</table>";
}
?>      