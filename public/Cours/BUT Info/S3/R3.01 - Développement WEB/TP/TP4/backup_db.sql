-- MariaDB dump 10.19  Distrib 10.11.6-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: mariadb    Database: r301_td3
-- ------------------------------------------------------
-- Server version	11.0.3-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `equipes`
--

DROP TABLE IF EXISTS `equipes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `equipes` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `code_pays` varchar(3) DEFAULT NULL,
  `nom_pays` varchar(30) NOT NULL,
  `poule` varchar(2) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=746 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `equipes`
--

LOCK TABLES `equipes` WRITE;
/*!40000 ALTER TABLE `equipes` DISABLE KEYS */;
INSERT INTO `equipes` VALUES
(526,'NZL','Nouvelle-Zelande','A'),
(527,'FRA','France','A'),
(528,'ITA','Italie','A'),
(529,'URU','Uruguay','A'),
(530,'NAM','Namibie\n','A'),
(531,'RSA','Afrique du Sud','B'),
(532,'IRL','Irlande','B'),
(533,'SCO','Ecosse','B'),
(534,'TGA','Tonga','B'),
(535,'ROU','Roumanie\n','B'),
(536,'WAL','Pays de Galles','C'),
(537,'AUS','Australie','C'),
(538,'FIJ','Fidji','C'),
(539,'GEO','Georgie','C'),
(540,'POR','Portugal\n','C'),
(541,'ENG','Angleterre','D'),
(542,'JPN','Japon','D'),
(543,'ARG','Argentine','D'),
(544,'SAM','Samoa','D'),
(545,'CHI','Chili','D'),
(546,'NZL','Nouvelle-Zelande','A'),
(547,'FRA','France','A'),
(548,'ITA','Italie','A'),
(549,'URU','Uruguay','A'),
(550,'NAM','Namibie\n','A'),
(551,'RSA','Afrique du Sud','B'),
(552,'IRL','Irlande','B'),
(553,'SCO','Ecosse','B'),
(554,'TGA','Tonga','B'),
(555,'ROU','Roumanie\n','B'),
(556,'WAL','Pays de Galles','C'),
(557,'AUS','Australie','C'),
(558,'FIJ','Fidji','C'),
(559,'GEO','Georgie','C'),
(560,'POR','Portugal\n','C'),
(561,'ENG','Angleterre','D'),
(562,'JPN','Japon','D'),
(563,'ARG','Argentine','D'),
(564,'SAM','Samoa','D'),
(565,'CHI','Chili','D'),
(566,'NZL','Nouvelle-Zelande','A'),
(567,'FRA','France','A'),
(568,'ITA','Italie','A'),
(569,'URU','Uruguay','A'),
(570,'NAM','Namibie\n','A'),
(571,'RSA','Afrique du Sud','B'),
(572,'IRL','Irlande','B'),
(573,'SCO','Ecosse','B'),
(574,'TGA','Tonga','B'),
(575,'ROU','Roumanie\n','B'),
(576,'WAL','Pays de Galles','C'),
(577,'AUS','Australie','C'),
(578,'FIJ','Fidji','C'),
(579,'GEO','Georgie','C'),
(580,'POR','Portugal\n','C'),
(581,'ENG','Angleterre','D'),
(582,'JPN','Japon','D'),
(583,'ARG','Argentine','D'),
(584,'SAM','Samoa','D'),
(585,'CHI','Chili','D'),
(586,'NZL','Nouvelle-Zelande','A'),
(587,'FRA','France','A'),
(588,'ITA','Italie','A'),
(589,'URU','Uruguay','A'),
(590,'NAM','Namibie\n','A'),
(591,'RSA','Afrique du Sud','B'),
(592,'IRL','Irlande','B'),
(593,'SCO','Ecosse','B'),
(594,'TGA','Tonga','B'),
(595,'ROU','Roumanie\n','B'),
(596,'WAL','Pays de Galles','C'),
(597,'AUS','Australie','C'),
(598,'FIJ','Fidji','C'),
(599,'GEO','Georgie','C'),
(600,'POR','Portugal\n','C'),
(601,'ENG','Angleterre','D'),
(602,'JPN','Japon','D'),
(603,'ARG','Argentine','D'),
(604,'SAM','Samoa','D'),
(605,'CHI','Chili','D'),
(606,'NZL','Nouvelle-Zelande','A'),
(607,'FRA','France','A'),
(608,'ITA','Italie','A'),
(609,'URU','Uruguay','A'),
(610,'NAM','Namibie\n','A'),
(611,'RSA','Afrique du Sud','B'),
(612,'IRL','Irlande','B'),
(613,'SCO','Ecosse','B'),
(614,'TGA','Tonga','B'),
(615,'ROU','Roumanie\n','B'),
(616,'WAL','Pays de Galles','C'),
(617,'AUS','Australie','C'),
(618,'FIJ','Fidji','C'),
(619,'GEO','Georgie','C'),
(620,'POR','Portugal\n','C'),
(621,'ENG','Angleterre','D'),
(622,'JPN','Japon','D'),
(623,'ARG','Argentine','D'),
(624,'SAM','Samoa','D'),
(625,'CHI','Chili','D'),
(626,'NZL','Nouvelle-Zelande','A'),
(627,'FRA','France','A'),
(628,'ITA','Italie','A'),
(629,'URU','Uruguay','A'),
(630,'NAM','Namibie\n','A'),
(631,'RSA','Afrique du Sud','B'),
(632,'IRL','Irlande','B'),
(633,'SCO','Ecosse','B'),
(634,'TGA','Tonga','B'),
(635,'ROU','Roumanie\n','B'),
(636,'WAL','Pays de Galles','C'),
(637,'AUS','Australie','C'),
(638,'FIJ','Fidji','C'),
(639,'GEO','Georgie','C'),
(640,'POR','Portugal\n','C'),
(641,'ENG','Angleterre','D'),
(642,'JPN','Japon','D'),
(643,'ARG','Argentine','D'),
(644,'SAM','Samoa','D'),
(645,'CHI','Chili','D'),
(646,'NZL','Nouvelle-Zelande','A'),
(647,'FRA','France','A'),
(648,'ITA','Italie','A'),
(649,'URU','Uruguay','A'),
(650,'NAM','Namibie\n','A'),
(651,'RSA','Afrique du Sud','B'),
(652,'IRL','Irlande','B'),
(653,'SCO','Ecosse','B'),
(654,'TGA','Tonga','B'),
(655,'ROU','Roumanie\n','B'),
(656,'WAL','Pays de Galles','C'),
(657,'AUS','Australie','C'),
(658,'FIJ','Fidji','C'),
(659,'GEO','Georgie','C'),
(660,'POR','Portugal\n','C'),
(661,'ENG','Angleterre','D'),
(662,'JPN','Japon','D'),
(663,'ARG','Argentine','D'),
(664,'SAM','Samoa','D'),
(665,'CHI','Chili','D'),
(666,'NZL','Nouvelle-Zelande','A'),
(667,'FRA','France','A'),
(668,'ITA','Italie','A'),
(669,'URU','Uruguay','A'),
(670,'NAM','Namibie\n','A'),
(671,'RSA','Afrique du Sud','B'),
(672,'IRL','Irlande','B'),
(673,'SCO','Ecosse','B'),
(674,'TGA','Tonga','B'),
(675,'ROU','Roumanie\n','B'),
(676,'WAL','Pays de Galles','C'),
(677,'AUS','Australie','C'),
(678,'FIJ','Fidji','C'),
(679,'GEO','Georgie','C'),
(680,'POR','Portugal\n','C'),
(681,'ENG','Angleterre','D'),
(682,'JPN','Japon','D'),
(683,'ARG','Argentine','D'),
(684,'SAM','Samoa','D'),
(685,'CHI','Chili','D'),
(686,'NZL','Nouvelle-Zelande','A'),
(687,'FRA','France','A'),
(688,'ITA','Italie','A'),
(689,'URU','Uruguay','A'),
(690,'NAM','Namibie\n','A'),
(691,'RSA','Afrique du Sud','B'),
(692,'IRL','Irlande','B'),
(693,'SCO','Ecosse','B'),
(694,'TGA','Tonga','B'),
(695,'ROU','Roumanie\n','B'),
(696,'WAL','Pays de Galles','C'),
(697,'AUS','Australie','C'),
(698,'FIJ','Fidji','C'),
(699,'GEO','Georgie','C'),
(700,'POR','Portugal\n','C'),
(701,'ENG','Angleterre','D'),
(702,'JPN','Japon','D'),
(703,'ARG','Argentine','D'),
(704,'SAM','Samoa','D'),
(705,'CHI','Chili','D'),
(706,'NZL','Nouvelle-Zelande','A'),
(707,'FRA','France','A'),
(708,'ITA','Italie','A'),
(709,'URU','Uruguay','A'),
(710,'NAM','Namibie\n','A'),
(711,'RSA','Afrique du Sud','B'),
(712,'IRL','Irlande','B'),
(713,'SCO','Ecosse','B'),
(714,'TGA','Tonga','B'),
(715,'ROU','Roumanie\n','B'),
(716,'WAL','Pays de Galles','C'),
(717,'AUS','Australie','C'),
(718,'FIJ','Fidji','C'),
(719,'GEO','Georgie','C'),
(720,'POR','Portugal\n','C'),
(721,'ENG','Angleterre','D'),
(722,'JPN','Japon','D'),
(723,'ARG','Argentine','D'),
(724,'SAM','Samoa','D'),
(725,'CHI','Chili','D'),
(726,'NZL','Nouvelle-Zelande','A'),
(727,'FRA','France','A'),
(728,'ITA','Italie','A'),
(729,'URU','Uruguay','A'),
(730,'NAM','Namibie\n','A'),
(731,'RSA','Afrique du Sud','B'),
(732,'IRL','Irlande','B'),
(733,'SCO','Ecosse','B'),
(734,'TGA','Tonga','B'),
(735,'ROU','Roumanie\n','B'),
(736,'WAL','Pays de Galles','C'),
(737,'AUS','Australie','C'),
(738,'FIJ','Fidji','C'),
(739,'GEO','Georgie','C'),
(740,'POR','Portugal\n','C'),
(741,'ENG','Angleterre','D'),
(742,'JPN','Japon','D'),
(743,'ARG','Argentine','D'),
(744,'SAM','Samoa','D'),
(745,'CHI','Chili','D');
/*!40000 ALTER TABLE `equipes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `matchs_final`
--

DROP TABLE IF EXISTS `matchs_final`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `matchs_final` (
  `id` int(11) NOT NULL,
  `equipe1` varchar(3) NOT NULL,
  `equipe2` varchar(3) NOT NULL,
  `date_match` date NOT NULL,
  `score_equipe1` int(11) NOT NULL,
  `score_equipe2` int(11) NOT NULL,
  `points_equipe1` int(11) NOT NULL,
  `points_equipe2` int(11) NOT NULL,
  `nom_pays1` varchar(50) NOT NULL,
  `nom_pays2` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `matchs_final`
--

LOCK TABLES `matchs_final` WRITE;
/*!40000 ALTER TABLE `matchs_final` DISABLE KEYS */;
/*!40000 ALTER TABLE `matchs_final` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `matchs_poule`
--

DROP TABLE IF EXISTS `matchs_poule`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `matchs_poule` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `equipe1` varchar(3) NOT NULL,
  `equipe2` varchar(3) NOT NULL,
  `date_match` date NOT NULL,
  `score_equipe1` int(11) NOT NULL,
  `score_equipe2` int(11) NOT NULL,
  `points_equipe1` int(11) NOT NULL,
  `points_equipe2` int(11) NOT NULL,
  `nom_pays1` varchar(50) NOT NULL,
  `nom_pays2` varchar(50) NOT NULL,
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=441 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `matchs_poule`
--

LOCK TABLES `matchs_poule` WRITE;
/*!40000 ALTER TABLE `matchs_poule` DISABLE KEYS */;
INSERT INTO `matchs_poule` VALUES
(401,'FRA','NZL','2023-09-08',27,13,4,0,'France','Nouvelle-Zelande'),
(402,'ITA','NAM','2023-09-09',52,8,5,0,'Italie','Namibie'),
(403,'IRL','ROU','2023-09-09',82,8,5,0,'Irlande','Roumanie'),
(404,'AUS','GEO','2023-09-09',35,15,5,0,'Australie','Georgie'),
(405,'ENG','ARG','2023-09-09',27,10,4,0,'Angleterre','Argentine'),
(406,'JPN','CHI','2023-09-10',42,12,5,0,'Japon','Chili'),
(407,'RSA','SCO','2023-09-10',18,3,4,0,'AfriqueduSud','Ecosse'),
(408,'WAL','FIJ','2023-09-10',32,26,5,2,'PaysdeGalles','Fidji'),
(409,'FRA','URU','2023-09-14',27,12,4,0,'France','Uruguay'),
(410,'NZL','NAM','2023-09-15',71,3,5,0,'Nouvelle-Zelande','Namibie'),
(411,'SAM','CHI','2023-09-16',43,10,5,0,'Samoa','Chili'),
(412,'WAL','POR','2023-09-16',28,8,5,0,'PaysdeGalles','Portugal'),
(413,'IRL','TGA','2023-09-16',59,16,5,0,'Irlande','Tonga'),
(414,'RSA','ROU','2023-09-17',76,0,5,0,'AfriqueduSud','Roumanie'),
(415,'AUS','FIJ','2023-09-17',15,22,1,4,'Australie','Fidji'),
(416,'ENG','JPN','2023-09-17',34,12,5,0,'Angleterre','Japon'),
(417,'ITA','URU','2023-09-20',38,17,5,0,'Italie','Uruguay'),
(418,'FRA','NAM','2023-09-21',96,0,5,0,'France','Namibie'),
(419,'ARG','SAM','2023-09-22',19,10,4,0,'Argentine','Samoa'),
(420,'GEO','POR','2023-09-23',18,18,1,1,'Georgie','Portugal'),
(421,'ENG','CHI','2023-09-23',71,0,5,0,'Angleterre','Chili'),
(422,'RSA','IRL','2023-09-23',8,13,1,4,'AfriqueduSud','Irlande'),
(423,'SCO','TGA','2023-09-24',45,17,5,0,'Ecosse','Tonga'),
(424,'WAL','AUS','2023-09-24',40,6,4,0,'PaysdeGalles','Australie'),
(425,'URU','NAM','2023-09-27',36,26,5,0,'Uruguay','Namibie'),
(426,'JPN','SAM','2023-09-28',28,22,4,1,'Japon','Samoa'),
(427,'NZL','ITA','2023-09-29',96,17,5,0,'Nouvelle-Zelande','Italie'),
(428,'ARG','CHI','2023-09-30',59,5,5,0,'Argentine','Chili'),
(429,'FIJ','GEO','2023-09-30',17,12,4,1,'Fidji','Georgie'),
(430,'SCO','ROU','2023-09-30',84,0,5,0,'Ecosse','Roumanie'),
(431,'AUS','POR','2023-10-01',34,14,5,0,'Australie','Portugal'),
(432,'RSA','TGA','2023-10-01',49,18,5,0,'AfriqueduSud','Tonga'),
(433,'NZL','URU','2023-10-05',73,0,5,0,'Nouvelle-Zelande','Uruguay'),
(434,'FRA','ITA','2023-10-06',60,7,5,0,'France','Italie'),
(435,'WAL','GEO','2023-10-07',43,19,5,0,'PaysdeGalles','Georgie'),
(436,'ENG','SAM','2023-10-07',18,17,4,0,'Angleterre','Samoa'),
(437,'IRL','SCO','2023-10-07',36,14,5,0,'Irlande','Ecosse'),
(438,'JPN','ARG','2023-10-08',27,39,0,5,'Japon','Argentine'),
(439,'TGA','ROU','2023-10-08',45,24,5,0,'Tonga','Roumanie'),
(440,'FIJ','POR','2023-10-08',23,24,1,4,'Fidji','Portugal');
/*!40000 ALTER TABLE `matchs_poule` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-12-18 22:28:32
