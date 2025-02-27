-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Hôte : biblio_db
-- Généré le : mer. 26 fév. 2025 à 16:07
-- Version du serveur : 5.7.44
-- Version de PHP : 8.2.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `biblio`
--

-- --------------------------------------------------------

--
-- Structure de la table `livres`
--

CREATE TABLE `livres` (
  `id` bigint(20) UNSIGNED NOT NULL,
  `nom` varchar(80) NOT NULL,
  `auteur` varchar(40) NOT NULL,
  `total` int(10) UNSIGNED NOT NULL,
  `pret` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `livres`
--

INSERT INTO `livres` (`id`, `nom`, `auteur`, `total`, `pret`) VALUES
(1, 'L\'Étranger (1942)', 'Albert Camus', 7, 0),
(2, 'Voyage au bout de la nuit (1932)', 'Louis-Ferdinand Céline', 4, 0),
(3, 'Les Fleurs du mal (1857)', 'Charles Baudelaire', 4, 0),
(4, 'Le Petit Prince (1943)', 'Antoine de Saint-Exupéry', 8, 0),
(5, 'Les Misérables (1862)', 'Victor Hugo', 9, 0),
(6, 'Les Liaisons dangereuses (1782)', 'Choderlos de Laclos', 7, 1),
(7, 'La Horde du contrevent (2004)', 'Alain Damasio', 9, 0),
(8, 'L\'Écume des jours (1947)', 'Boris Vian', 2, 0),
(9, 'Le Comte de Monte-Cristo (1844)', 'Alexandre Dumas', 7, 0),
(10, 'Madame Bovary (1857)', 'Gustave Flaubert', 11, 2),
(11, 'Cyrano de Bergerac (1897)', 'Edmond Rostand', 13, 0),
(12, 'Fables (1694)', 'Jean de La Fontaine', 4, 0),
(13, 'Bel-Ami (1885)', 'Guy de Maupassant', 11, 0),
(14, 'À la recherche du temps perdu (1927)', 'Marcel Proust', 11, 0),
(15, 'La Promesse de l\'aube', 'Romain Gary / Émile Ajar', 4, 0),
(16, 'Le Rouge et le Noir (1830)', 'Stendhal', 7, 0),
(17, 'La Nuit des temps (1968)', 'René Barjavel', 7, 2),
(18, 'La Peste (1947)', 'Albert Camus', 7, 3),
(19, 'Candide ou l\'Optimisme (1759)', 'Voltaire', 4, 0),
(20, 'Le Horla (1886)', 'Guy de Maupassant', 11, 0),
(21, 'Germinal (1885)', 'Émile Zola', 5, 0),
(22, 'Gagner la guerre (2009)', 'Jean-Philippe Jaworski', 8, 0),
(23, 'Notre-Dame de Paris (1831)', 'Victor Hugo', 9, 0),
(24, 'Les Trois Mousquetaires (1844)', 'Alexandre Dumas', 7, 0),
(25, 'Vingt Mille Lieues sous les mers (1869)', 'Jules Verne', 4, 0),
(26, 'Du côté de chez Swann (1913)', 'Marcel Proust', 11, 0),
(27, 'Les Fourmis (1991)', 'Bernard Werber', 4, 0),
(28, 'Le Père Goriot (1835)', 'Honoré de Balzac', 14, 0),
(29, 'L\'Assommoir (1877)', 'Émile Zola', 5, 2),
(30, 'Dom Juan (1665)', 'Molière', 4, 0),
(31, 'Les Chants de Maldoror (1869)', 'Comte de Lautréamont (Isidore Ducasse)', 10, 0),
(32, 'Le Dernier Jour d\'un condamné (1829)', 'Victor Hugo', 9, 0),
(33, 'Les Rois maudits (1995)', 'Maurice Druon', 2, 0),
(34, 'Phèdre (1677)', 'Jean Racine', 4, 1),
(35, 'Mémoires d\'Hadrien (1951)', 'Marguerite Yourcenar', 4, 0),
(36, 'Illusions perdues (1839)', 'Honoré de Balzac', 14, 0),
(37, 'Antigone (1944)', 'Jean Anouilh', 10, 0),
(38, 'Alcools (1913)', 'Guillaume Apollinaire', 4, 0),
(39, 'La Condition humaine (1933)', 'André Malraux', 10, 0),
(40, 'La Zone du dehors (2001)', 'Alain Damasio', 9, 3),
(41, 'La Vie devant soi (1975)', 'Romain Gary / Émile Ajar', 4, 0),
(42, 'En attendant Bojangles (2016)', 'Olivier Bourdeaut', 11, 0),
(43, 'Vernon Subutex, tome 1 (2015)', 'Virginie Despentes', 7, 0),
(44, 'L\'Éducation sentimentale (1869)', 'Gustave Flaubert', 11, 2),
(45, 'L\'Île mystérieuse (1874)', 'Jules Verne', 4, 0),
(46, 'Les Fiancés de l\'hiver (2013)', 'Christelle Dabos', 7, 0),
(47, 'Ravage (1943)', 'René Barjavel', 7, 0),
(48, 'Le Spleen de Paris (1869)', 'Charles Baudelaire', 4, 0),
(49, 'La Planète des singes (1963)', 'Pierre Boulle', 4, 0),
(50, 'Le Misanthrope (1666)', 'Molière', 4, 0),
(51, 'Le Tour du monde en 80 jours (1873)', 'Jules Verne', 4, 1),
(52, 'J\'irai cracher sur vos tombes (1946)', 'Boris Vian', 2, 0),
(53, 'À l\'ombre des jeunes filles en fleurs (1919)', 'Marcel Proust', 11, 0),
(54, 'Les Essais (1595)', 'Michel de Montaigne', 4, 0),
(55, 'Au bonheur des dames (1883)', 'Émile Zola', 5, 0),
(56, 'Les Contemplations (1856)', 'Victor Hugo', 9, 3),
(57, 'La Chute (1956)', 'Albert Camus', 7, 0),
(58, 'Les Faux-Monnayeurs (1925)', 'André Gide', 4, 0),
(59, 'Le Cid (1637)', 'Pierre Corneille', 4, 0),
(60, 'Malevil (1972)', 'Robert Merle', 4, 0),
(61, 'Caligula (1944)', 'Albert Camus', 7, 0),
(62, 'Au revoir là-haut (2013)', 'Pierre Lemaitre', 4, 0),
(63, 'Voyage au centre de la Terre (1864)', 'Jules Verne', 4, 0),
(64, 'L\'Homme qui rit (1869)', 'Victor Hugo', 9, 0),
(65, 'La Religieuse (1796)', 'Denis Diderot', 11, 0),
(66, 'La Cantatrice chauve (1950)', 'Eugène Ionesco', 9, 0),
(67, 'Les Cerfs-volants (1980)', 'Romain Gary / Émile Ajar', 4, 0),
(68, 'Paroles (1946)', 'Jacques Prévert', 11, 2),
(69, 'Discours de la servitude volontaire (1576)', 'Étienne de La Boétie', 4, 0),
(70, 'Le Grand Meaulnes (1913)', 'Alain-Fournier', 4, 0),
(71, 'L\'Amant (1984)', 'Marguerite Duras', 7, 0),
(72, 'Zazie dans le métro (1959)', 'Raymond Queneau', 10, 0),
(73, 'Pensées (1670)', 'Blaise Pascal', 7, 0),
(74, 'Bérénice (1670)', 'Jean Racine', 4, 0),
(75, 'Le Rivage des Syrtes (1951)', 'Julien Gracq', 10, 3),
(76, 'Les Thanatonautes (1994)', 'Bernard Werber', 4, 0),
(77, 'Le Soleil des Scorta (2004)', 'Laurent Gaudé', 10, 0),
(78, 'Le Deuxième Sexe, I (1949)', 'Simone de Beauvoir', 4, 0),
(79, 'Mort à crédit (1936)', 'Louis-Ferdinand Céline', 4, 0),
(80, 'Thérèse Raquin (1867)', 'Émile Zola', 5, 1),
(81, 'Une Saison en enfer (1873)', 'Arthur Rimbaud', 13, 0),
(82, 'Le Bateau ivre (1871)', 'Arthur Rimbaud', 13, 0),
(83, 'Nana (1880)', 'Émile Zola', 5, 0),
(84, 'Gargantua (1534)', 'François Rabelais', 7, 0),
(85, 'Janua Vera (2007)', 'Jean-Philippe Jaworski', 8, 0),
(86, 'Petit pays (2016)', 'Gaël Faye', 4, 0),
(87, 'La Chartreuse de Parme (1839)', 'Stendhal', 7, 2),
(88, 'Le Mystère de la chambre jaune (1907)', 'Gaston Leroux', 10, 0),
(89, 'Les Mains libres (1937)', 'Paul Éluard et Man Ray', 8, 0),
(90, 'La Dame aux camélias (1848)', 'Alexandre Dumas fils', 7, 0),
(91, 'Les Confessions (1782)', 'Jean-Jacques Rousseau', 10, 0),
(92, 'Lorenzaccio (1834)', 'Alfred de Musset', 11, 0),
(93, 'Le Roi des Aulnes (1970)', 'Michel Tournier', 4, 0),
(94, 'Les Deux Étendards (1951)', 'Lucien Rebatet', 11, 0),
(95, 'Les Particules élémentaires (1998)', 'Michel Houellebecq', 10, 2);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `livres`
--
ALTER TABLE `livres`
  MODIFY `id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=96;
COMMIT;

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `livres`
--
ALTER TABLE `livres`
  MODIFY `id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=96;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
