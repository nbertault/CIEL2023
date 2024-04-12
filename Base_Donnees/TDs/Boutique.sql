-- phpMyAdmin SQL Dump
-- version 4.6.6deb4
-- https://www.phpmyadmin.net/
--
-- Client :  localhost:3306
-- Généré le :  Mar 02 Avril 2024 à 10:37
-- Version du serveur :  10.1.41-MariaDB-0+deb9u1
-- Version de PHP :  7.0.33-0+deb9u10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `TD2_xxxxxx`
--

-- --------------------------------------------------------

--
-- Structure de la table `articles`
--

CREATE TABLE `articles` (
  `idarticle` int(11) NOT NULL,
  `nom` varchar(50) NOT NULL,
  `reference` varchar(50) NOT NULL,
  `prix` float NOT NULL,
  `idfournisseur` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
--
-- Contenu de la table `articles`
--
INSERT INTO `articles` (`idarticle`, `nom`, `reference`, `prix`, `idfournisseur`) VALUES
(1, 'VELO ENFANT', 'VE-642/05', 85, 1),
(2, 'MONTRE FEMME', 'MF-1057/07', 160, 3),
(3, 'HALOGENE', 'HA-32478/06', 345, 2),
(4, 'HALOGENE LUXE', 'HL-32479/06', 75, 2),
(5, 'HALOGENE MIXTE', 'HL-32480/06', 69, 2),
(6, 'COUVERTURE BLEUE', 'CB-0169/05', 12, 2),
(7, 'COUVERTURE ROUGE', 'CR-0169/05', 12, 2),
(8, 'COUVERTURE JAUNE', 'CJ-0169/05', 12, 2),
(9, 'TABOURET PLASTIQUE', 'TP-54231/05', 9, 2),
(10, 'LAMPADAIRE', 'LA-5897/06', 45, 2),
(11, 'VELO ADULTE', 'VA-643/05', 485, 1),
(12, 'MONTRE HOMME', 'MH-063/07', 195, 3),
(13, 'TASSE DECO1', 'TD-9178/08', 10, 3),
(14, 'TASSE DECO2', 'TD-9278/08', 10, 3),
(15, 'TASSE DECO3', 'TD-9378/08', 10, 3),
(16, 'TASSE DECO4', 'TD-9478/08', 10, 3),
(17, 'VASE ROSE', 'VR-23225/07', 35, 3),
(18, 'BALLON ROND', 'BR-88954/08', 12, 1),
(19, 'BALLON OVALE', 'BO-88955/08', 14, 1),
(20, 'MONTRE ENFANT', 'ME-102/05', 17.5, 3);
-- --------------------------------------------------------
--
-- Structure de la table `clients`
--
CREATE TABLE `clients` (
  `idclient` int(11) NOT NULL,
  `nom` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
--
-- Contenu de la table `clients`
--
INSERT INTO `clients` (`idclient`, `nom`) VALUES
(1, 'DUPONT'),
(2, 'FROGARIN'),
(3, 'DE MARNETS'),
(4, 'MAUPINTON'),
(5, 'ALISSANNE'),
(6, 'BOUTRISE'),
(7, 'GELIF'),
(8, 'ZELAZNOHYG'),
(9, 'BOND'),
(10, 'LUCAS');
-- --------------------------------------------------------
--
-- Structure de la table `commandes`
--
CREATE TABLE `commandes` (
  `idcommande` int(11) NOT NULL,
  `idclient` int(11) NOT NULL,
  `idarticle` int(11) NOT NULL,
  `quantite` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
--
-- Contenu de la table `commandes`
--
INSERT INTO `commandes` (`idcommande`, `idclient`, `idarticle`, `quantite`) VALUES
(1, 9, 2, 4),
(2, 7, 4, 1),
(3, 6, 14, 3),
(4, 1, 11, 1),
(5, 9, 2, 1),
(6, 9, 12, 1);
-- --------------------------------------------------------
--
-- Structure de la table `fournisseurs`
--
CREATE TABLE `fournisseurs` (
  `idfournisseur` int(11) NOT NULL,
  `nom` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
--
-- Contenu de la table `fournisseurs`
--
INSERT INTO `fournisseurs` (`idfournisseur`, `nom`) VALUES
(1, 'Jouets S.A.'),
(2, 'Cadeaux S.A.R.L.'),
(3, 'Gifts Inc.'),
(4, 'L3S');
-- --------------------------------------------------------
--
-- Index pour les tables exportées
--
--
-- Index pour la table `articles`
--
ALTER TABLE `articles`
  ADD PRIMARY KEY (`idarticle`),
  ADD KEY `idfournisseur` (`idfournisseur`);
--
-- Index pour la table `clients`
--
ALTER TABLE `clients`
  ADD PRIMARY KEY (`idclient`);
--
-- Index pour la table `commandes`
--
ALTER TABLE `commandes`
  ADD PRIMARY KEY (`idcommande`),
  ADD KEY `idclient` (`idclient`),
  ADD KEY `idarticle` (`idarticle`);
--
-- Index pour la table `fournisseurs`
--
ALTER TABLE `fournisseurs`
  ADD PRIMARY KEY (`idfournisseur`);
-- --------------------------------------------------------
--
-- AUTO_INCREMENT pour les tables exportées
--
--
-- AUTO_INCREMENT pour la table `articles`
--
ALTER TABLE `articles`
  MODIFY `idarticle` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;
--
-- AUTO_INCREMENT pour la table `clients`
--
ALTER TABLE `clients`
  MODIFY `idclient` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
--
-- AUTO_INCREMENT pour la table `commandes`
--
ALTER TABLE `commandes`
  MODIFY `idcommande` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT pour la table `fournisseurs`
--
ALTER TABLE `fournisseurs`
  MODIFY `idfournisseur` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
-- --------------------------------------------------------
--
-- Contraintes pour les tables exportées
--
--
-- Contraintes pour la table `articles`
--
ALTER TABLE `articles`
  ADD CONSTRAINT `article_ibfk_1` FOREIGN KEY (`idfournisseur`) REFERENCES `fournisseurs` (`idfournisseur`);
--
-- Contraintes pour la table `commandes`
--
ALTER TABLE `commandes`
  ADD CONSTRAINT `commande_ibfk_1` FOREIGN KEY (`idclient`) REFERENCES `clients` (`idclient`),
  ADD CONSTRAINT `commande_ibfk_2` FOREIGN KEY (`idarticle`) REFERENCES `articles` (`idarticle`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
