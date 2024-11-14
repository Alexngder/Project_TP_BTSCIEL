/* CONNECTION DE CPLUSPLUS A UNE BDD SUR MYSQL */

/* Les includes à placer ci-dessous */
#include <stdlib.h>
#include <iostream>
#include <string>

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
    char waiting;
    int choix_cat, ID_magasin, ID_articles, quantite,choix=5;
    const string categorie[4] = {"Appareil Electronique", "Eclairage", "Mobilier", "Vetement"};

    try {

        while ((choix>=1) && (choix<6)){

        // tentative de connection au serveur (try=essai)
        sql::Driver *driver;              // objet gestionnaire de connexion réseau
        sql::Connection *con;             // objet gestionnaire de session serveur
        sql::Statement *stmt;             // objet c++ de transaction en SQL
        sql::ResultSet *res;              // objet vue reponse du serveur de bdd
        sql::PreparedStatement *pstmt;    // objet sécurisant la transaction 

        /* Créer une connexion */
        driver = get_driver_instance();
        /* le protocole de dialogue avec le serveur est TCP */
        con = driver->connect("tcp://127.0.0.1:3306", "admin", "admin");

        /* Etre connecté à la base de données */
        con->setSchema("marsmag");

    

        system("clear");
        cout << "Voir stock total (1)" << endl;
        cout << "Voir categorie un article dans un magasin (2)" << endl;
        cout << "Supprimer un magasin de la liste (3)" << endl;
        cout << "Inserer nombre exemplaire d'une categorie spécifier pour un magasin (4)" << endl;
        cout << "Supprimer une categorie qui n'est plus produite (5)" << endl;
        cout<<" Pour sortir du programme (6)"<<endl;
        cout << "Que souhaitez-vous faire : ";
        cin >> choix;
        cout << endl;

        switch (choix) {
            case 1:
                system("clear");
                pstmt = con->prepareStatement("SELECT id_article, nom_article, categorie, marque, quantite, id_magasin FROM articles");
                res = pstmt->executeQuery();

                cout << "\t RESULTAT DE RECHERCHE" << endl;
                // boucle d'extraction de chaque tuple de la vue
                while (res->next())
                    cout << "\t | id_article : " << res->getInt("id_article") << "| nom article : " << res->getString("nom_article") << "| categorie : " << res->getString("categorie") << "| marque : " << res->getString("marque") << "| quantite : " << res->getInt("quantite") << "| id_magasin : " << res->getInt("id_magasin") << "|" << endl;
                
                delete res;
                delete pstmt;
                delete con;
                cout<<"Appuyer sur n'importe quel lettre pour retourner dans le menu de magasin"<<endl;
                cin>>waiting;
                break;

            case 2:
                system("clear");
                cout << "Quel magasin souhaitez-vous choisir ? (1/3) ";
                cin >> ID_magasin;
                cout << endl;
                cout << "Appareil Electronique (1)" << endl;
                cout << "Eclairage (2)" << endl;
                cout << "Mobilier (3)" << endl;
                cout << "Vetement (4)" << endl;
                cout << "Quelle categorie ? : ";
                cin >> choix_cat;
                cout << endl;
                if (choix_cat >=1 && choix_cat <=4){
                    pstmt = con->prepareStatement("SELECT id_article, nom_article, categorie, marque, quantite, id_magasin FROM articles WHERE categorie= ? AND id_magasin=?;");
                    pstmt->setString(1, categorie[choix_cat - 1]);
                    pstmt->setInt(2, ID_magasin);
                    res = pstmt->executeQuery();
                    cout << " RESULTAT DE RECHERCHE :" << endl;
                    while (res->next())
                    cout << " | id_article : " << res->getInt("id_article") << "| nom article : " << res->getString("nom_article") << "| categorie : " << res->getString("categorie") << "| marque : " << res->getString("marque") << "| quantite : " << res->getInt("quantite") << "| id_magasin : " << res->getInt("id_magasin") << "|" << endl;
                }else{
                    cout << "Aucune categorie ne correspond à ce numero." << endl;
                }
                delete res;
                delete pstmt;
                delete con;
                cout<<"Appuyer sur n'importe quel lettre pour retourner dans le menu de magasin"<<endl;
                cin>>waiting;
                break;

            case 3:
                system("clear");
                pstmt = con->prepareStatement("DELETE FROM magasins WHERE id_magasin = ?");
                cout << "Quel magasin à supprimer ? ";
                cin >> ID_magasin;
                pstmt->setInt(1, ID_magasin);
                pstmt->executeQuery(); // utiliser executeQuery pour DELETE
                cout << "Magasin supprimé." << endl;

                delete pstmt;
                delete con;
                cout<<"Appuyer sur n'importe quel lettre pour retourner dans le menu de magasin"<<endl;
                cin>>waiting;
                break;

            case 4:
                system("clear");
                cout << "Quel est votre magasin ? : ";
                cin >> ID_magasin;
                cout << endl;
                cout << "Quel est l'identifiant de l'article ? : ";
                cin >> ID_articles;
                cout << endl;
                cout << "Saisir la quantité de l'article : ";
                cin >> quantite;
                cout << endl;
                pstmt = con->prepareStatement("UPDATE articles SET quantite = ? WHERE id_article = ? AND id_magasin = ?;");
                pstmt->setInt(1, quantite);
                pstmt->setInt(2, ID_articles);
                pstmt->setInt(3, ID_magasin);
                pstmt->executeQuery(); // utiliser executeQuery pour UPDATE
                cout << "Quantité mise à jour." << endl;

                delete pstmt;
                delete con;
                cin>>waiting;
                break;

            case 5:
                system("clear");
                pstmt = con->prepareStatement("DELETE FROM articles WHERE id_article = ?;");
                cout << "ID de l'article à supprimer ? ";
                cin >> ID_articles;
                pstmt->setInt(1, ID_articles);
                pstmt->executeQuery(); // utiliser executeQuery pour DELETE
                cout << "Article supprimé." << endl;

                delete pstmt;
                delete con;
                cin>>waiting;
                break;

            default:
                cout << "Fin du Programme" << endl;
                break;
        }
        }
    } 
    catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    // Saut de ligne
    cout << endl;

    // Dire à l'OS que tout s'est bien passé
    return EXIT_SUCCESS;
}
