-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le : ven. 11 oct. 2024 à 16:36
-- Version du serveur : 10.6.18-MariaDB-0ubuntu0.22.04.1
-- Version de PHP : 8.1.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `marsmag`
--

-- --------------------------------------------------------

--
-- Structure de la table `articles`
--

CREATE TABLE `articles` (
  `id_article` varchar(255) NOT NULL,
  `nom_article` varchar(255) DEFAULT NULL,
  `categorie` varchar(255) DEFAULT NULL,
  `marque` varchar(255) DEFAULT NULL,
  `quantite` int(11) DEFAULT NULL,
  `id_magasin` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `articles`
--

INSERT INTO `articles` (`id_article`, `nom_article`, `categorie`, `marque`, `quantite`, `id_magasin`) VALUES
('1', 'T-shirt', 'Vetement', 'asics', 15, 1),
('10', 'Clavier', 'Appareil Electronique', 'Lenovo', 20, 2),
('11', 'Pc Portable', 'Appareil Electronique', 'MSI', 96, 3),
('15', 'Lampe', 'Eclairage', 'Artemide', 10, 2),
('2', 'Ecran', 'Appareil Electronique', 'Asus', 99, 1),
('3', 'Smartphone', 'Appareil Electronique', 'Xiaomi', 65, 3),
('4', 'Ecran', 'Appareil Electronique', 'Samsung', 20, 2),
('5', 'Chaise', 'Mobilier', 'IKEA', 99, 1),
('6', 'Ecran', 'Appareil Electronique', 'LG', 20, 2),
('7', 'Table', 'Mobilier', 'IKEA', 99, 1),
('8', 'Chaussure', 'Vetement', 'asics', 99, 1),
('9', 'Lampadaire', 'Eclairage', 'Artemide', 10, 2);

-- --------------------------------------------------------

--
-- Structure de la table `magasins`
--

CREATE TABLE `magasins` (
  `id_magasin` int(11) NOT NULL,
  `nom_magasin` varchar(255) DEFAULT NULL,
  `adresse` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `magasins`
--

INSERT INTO `magasins` (`id_magasin`, `nom_magasin`, `adresse`) VALUES
(1, 'Grand Littoral', '11 Avenue de St antoine, 13016 Marseille'),
(2, 'Terrasse du Port', '9 Quai du Lazaret, 13002 Marseille'),
(3, 'Carrefour', '3 rue de liberation,13001 Marseille'),
(4, 'Auchan', '15eme rue de Hege, 13015 Marseille'),
(5, 'Super U', 'Rue de Canebiere, 13001, Marseille');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `articles`
--
ALTER TABLE `articles`
  ADD PRIMARY KEY (`id_article`),
  ADD KEY `id_magasin` (`id_magasin`);

--
-- Index pour la table `magasins`
--
ALTER TABLE `magasins`
  ADD PRIMARY KEY (`id_magasin`);

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `articles`
--
ALTER TABLE `articles`
  ADD CONSTRAINT `articles_ibfk_1` FOREIGN KEY (`id_magasin`) REFERENCES `magasins` (`id_magasin`) ON DELETE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
