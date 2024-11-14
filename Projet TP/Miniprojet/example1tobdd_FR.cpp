/* CONNECTION DE CPLUSPLUS A UNE BDD SUR MYSQL */

/* Les includes à placer ci-dessous */
#include <stdlib.h>
#include <iostream>

/*
  Inclure directement et toujours les differents
  headers du connecteur C++ nommés:cppconn/ incluant mysql_driver.h
  et mysql_util.h (and mysql_connection.h).
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

int main(void)
{
cout << endl;
cout << "DEMANDE DES HOTELS DU VAL DE MARNE" << endl;

try { // tentative de connection au serveur (try=essai)
  sql::Driver *driver; //objet gestionnaire de connexion réseau
  sql::Connection *con;//objet gestionnaire de session serveur
  sql::Statement *stmt;//objet c++ de transaction en sql
  sql::ResultSet *res; //objet vue reponse du serveur de bdd
  sql::PreparedStatement *pstmt; //objet sécurisant la transaction 

  /* Creer une connection */
  driver = get_driver_instance();
  /* le protocole de dialogue avec le serveur est TCP */
  /* le mot localhost egale 127.0.0.1 */
  /* le port d ecoute du serveur de bdd est le 3306 */
  con = driver->connect("tcp://127.0.0.1:3306", "admin", "admin");
  
  /* Etre connecte a la base de donnees hotels */
  con->setSchema("hotels");
  
  /* PARTIE 1 NON ENCORE ETUDIEE */
  /*
  stmt = con->createStatement();
  stmt->execute("DROP TABLE IF EXISTS test");
  stmt->execute("CREATE TABLE test(id INT)");
  delete stmt;
  */
  
  /* PARTIE 2 NON ENCORE ETUDIEE */
  /* '?' is the supported placeholder syntax */
  /*
  pstmt = con->prepareStatement("INSERT INTO test(id) VALUES (?)");
  for (int i = 1; i <= 10; i++) {
    pstmt->setInt(1, i); // premier ? on remplace par la valeur de i
    pstmt->executeUpdate();
  }
  delete pstmt;
  */
  
  /* PARTIE 3 LMD */
  /* Selectionner par ordre croissant de idhotel les renseignements */
  pstmt = con->prepareStatement("SELECT idhotel,nom,ville,dept,etoiles FROM hotel WHERE dept=94 ORDER BY idhotel ASC");
  res = pstmt->executeQuery();

  cout <<"\t RESULTAT DE RECHERCHE"<<endl;
  /* si ci-dessous décommenté alors par ordre décroissant */
  //res->afterLast();
  
  // boucle d'extraction de chaque tuple de la vue
  while (res->next())
    	cout << "\t | idhotel : " << res->getInt("idhotel") <<"| nom hotel : " << res->getString("nom") <<"| ville : " << res->getString("ville") <<"| departement : " << res->getInt("dept") <<"| etoiles : " << res->getInt("etoiles") <<"|"<<endl;
  delete res;
  // on detruit les objets de la heap
  delete pstmt;
  delete con;

}
// capturer une erreur (cad une exception) dans la section try
// et renseigner le developpeur
catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}

// saut de ligne
cout << endl;

// dire à operating system que tout s est bien passe
return EXIT_SUCCESS;
}
