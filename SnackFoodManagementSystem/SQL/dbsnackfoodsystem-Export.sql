-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jul 02, 2021 at 04:03 PM
-- Server version: 10.4.16-MariaDB
-- PHP Version: 7.4.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `dbsnackfoodsystem`
--

-- --------------------------------------------------------

--
-- Table structure for table `administrator`
--

CREATE TABLE `administrator` (
  `ADMIN_ID` varchar(15) NOT NULL,
  `ADMIN_PASSWORD` varchar(15) NOT NULL,
  `ADMIN_NAME` varchar(30) NOT NULL,
  `ADMIN_PHONE` char(12) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `administrator`
--

INSERT INTO `administrator` (`ADMIN_ID`, `ADMIN_PASSWORD`, `ADMIN_NAME`, `ADMIN_PHONE`) VALUES
('admin', 'admin', '', ''),
('aiman10', 'aiman10@abcde', 'Muhammad Aiman Bin Faizal', '0115236589'),
('aiman92', 'aiman92@12345', 'Mohd Aiman', '0177512468'),
('alif20', 'alif20@12345', 'Muhammad Alif', '0117856465'),
('faiz20', 'faiz@abcd', 'Muhammad Faiz Bin Ahmad Faizal', '0115463258'),
('faizal95', 'faizal95@12345', 'Faizal Husin', '0177516324'),
('husin20', 'husin20@abcde', 'Muhd Husin', '0101542365'),
('sufian20', 'sufian20@abcde', 'Mohammad Sufian Bin Fuad', '0117856246');

-- --------------------------------------------------------

--
-- Table structure for table `product`
--

CREATE TABLE `product` (
  `PRODUCT_ID` int(11) NOT NULL,
  `PRODUCT_NAME` varchar(30) NOT NULL,
  `PRODUCT_PRICE` double NOT NULL,
  `PRODUCT_STOCK` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `product`
--

INSERT INTO `product` (`PRODUCT_ID`, `PRODUCT_NAME`, `PRODUCT_PRICE`, `PRODUCT_STOCK`) VALUES
(1000, 'Kerepek Ubi Pedas (500g)', 10, 28),
(1001, 'Kerepek Ubi Pedas (1000g)', 20, 18),
(1002, 'Kerepek Ubi Jagung (500g)', 10, 20),
(1003, 'Kerepek Ubi Jagung (1000g)', 20, 37),
(1006, 'Kerepek Ubi Masin (500g)', 10, 19),
(1007, 'Kerepek Ubi Masin (1000g)', 20, 27),
(1008, 'Kerepek Ubi BBQ   (500g)', 10, 30),
(1009, 'Kerepek Ubi BBQ   (1000g)', 20, 20),
(1010, 'Kerepek Ubi Cheese (500g)', 12, 28),
(1011, 'Kerepek Ubi Cheese (1000g)', 12, 23),
(1012, 'Kerepek Ubi Racik (500g)', 10, 20),
(1013, 'Kerepek Ubi Racik (1000g)', 20, 20),
(1016, 'Kerepek Ubi Pedas (10kg)', 200, 20),
(1017, 'Kerepek Ubi Jagung (10kg)', 200, 10),
(1018, 'Kerepek Ubi Masin (10kg)', 200, 10),
(1019, 'Kerepek Ubi BBQ    (10kg)', 200, 10),
(1020, 'Kerepek Ubi Cheese (10kg)', 200, 10),
(1021, 'Kerepek Ubi Racik (10kg)', 200, 20);

-- --------------------------------------------------------

--
-- Table structure for table `purchase`
--

CREATE TABLE `purchase` (
  `PURCHASE_ID` int(11) NOT NULL,
  `PRODUCT_ID` int(11) NOT NULL,
  `PURCHASE_QUANTITY` int(11) NOT NULL,
  `PURCHASE_TOTALPRICE` double NOT NULL,
  `RECEIPT_NO` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `salerecord`
--

CREATE TABLE `salerecord` (
  `SALE_ID` int(11) NOT NULL,
  `PURCHASE_ID` int(11) NOT NULL,
  `PRODUCT_ID` int(11) NOT NULL,
  `PURCHASE_QUANTITY` int(11) NOT NULL,
  `PURCHASE_TOTALPRICE` double NOT NULL,
  `DATESOLD` datetime NOT NULL DEFAULT current_timestamp(),
  `RECEIPT_NO` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `salerecord`
--

INSERT INTO `salerecord` (`SALE_ID`, `PURCHASE_ID`, `PRODUCT_ID`, `PURCHASE_QUANTITY`, `PURCHASE_TOTALPRICE`, `DATESOLD`, `RECEIPT_NO`) VALUES
(4, 2080, 1000, 2, 20, '2021-06-01 12:31:45', 0),
(5, 2081, 1001, 2, 40, '2021-06-02 12:31:45', 0),
(6, 2082, 1002, 1, 10, '2021-06-03 12:31:45', 0),
(7, 2083, 1000, 1, 10, '2021-06-04 12:32:55', 0),
(8, 2084, 1002, 1, 10, '2021-06-04 12:32:55', 0),
(9, 2085, 1003, 1, 20, '2021-06-04 12:32:55', 0),
(10, 2086, 1000, 1, 10, '2021-06-04 18:57:33', 0),
(11, 2087, 1001, 1, 20, '2021-06-04 18:57:33', 0),
(12, 2088, 1002, 1, 10, '2021-06-04 18:57:33', 0),
(13, 2090, 1000, 1, 10, '2021-06-04 21:42:31', 0),
(14, 2091, 1001, 1, 20, '2021-06-04 21:42:31', 0),
(16, 2092, 1002, 1, 10, '2021-06-04 21:43:13', 0),
(17, 2093, 1003, 1, 20, '2021-06-04 21:43:13', 0),
(19, 2095, 1003, 2, 40, '2021-06-05 17:32:04', 0),
(22, 2099, 1001, 2, 40, '2021-06-05 17:52:24', 0),
(23, 2105, 1000, 2, 20, '2021-06-05 22:20:07', 0),
(24, 2106, 1001, 2, 40, '2021-06-05 22:20:07', 0),
(25, 2107, 1002, 1, 10, '2021-06-05 22:20:07', 0),
(26, 2108, 1000, 1, 10, '2021-06-05 22:46:56', 0),
(27, 2109, 1001, 1, 20, '2021-06-05 22:46:56', 0),
(28, 2110, 1002, 1, 10, '2021-06-05 22:46:56', 0),
(29, 2114, 1000, 1, 10, '2021-06-06 01:02:42', 0),
(30, 2115, 1001, 1, 20, '2021-06-06 01:02:42', 0),
(31, 2117, 1003, 1, 20, '2021-06-07 16:38:30', 0),
(32, 2118, 1001, 1, 20, '2021-06-08 18:17:46', 0),
(33, 2119, 1003, 1, 20, '2021-06-07 18:17:46', 0),
(35, 2121, 1002, 1, 10, '2021-06-07 18:25:15', 0),
(40, 2126, 1000, 1, 10, '2021-06-09 10:03:44', 0),
(41, 2127, 1001, 1, 20, '2021-06-09 10:03:44', 0),
(42, 2128, 1002, 1, 10, '2021-06-09 10:03:44', 0),
(43, 2129, 1000, 1, 10, '2021-06-09 10:03:44', 0),
(47, 2130, 1000, 1, 10, '2021-06-09 12:01:38', 0),
(48, 2131, 1001, 3, 60, '2021-06-09 12:01:38', 0),
(49, 2132, 1003, 2, 40, '2021-06-09 12:01:38', 0),
(50, 2133, 1001, 1, 20, '2021-06-09 12:02:44', 0),
(52, 2134, 1000, 1, 10, '2021-06-09 13:23:07', 0),
(53, 2135, 1001, 1, 20, '2021-06-09 13:23:07', 0),
(55, 2137, 1002, 1, 10, '2021-06-09 14:15:28', 0),
(56, 2138, 1000, 1, 10, '2021-06-09 14:15:28', 0),
(57, 2020, 1000, 1, 10, '2021-06-14 13:59:27', 0),
(58, 2021, 1000, 1, 10, '2021-06-14 14:00:28', 0),
(59, 2022, 1000, 1, 10, '2021-06-14 14:01:52', 0),
(60, 2023, 1003, 1, 20, '2021-06-14 14:02:27', 0),
(61, 2024, 1003, 1, 20, '2021-06-14 14:04:27', 0),
(62, 2025, 1001, 1, 20, '2021-06-14 14:05:20', 0),
(63, 2026, 1000, 2, 20, '2021-06-14 17:23:16', 0),
(64, 2027, 1000, 2, 20, '2021-06-14 17:23:16', 0),
(65, 2028, 1000, 1, 10, '2021-06-14 17:23:16', 0),
(66, 2029, 1001, 1, 20, '2021-06-14 17:23:16', 0),
(70, 2030, 1000, 1, 10, '2021-06-14 17:27:51', 0),
(71, 2031, 1001, 1, 20, '2021-06-14 17:27:51', 0),
(72, 2032, 1002, 1, 10, '2021-06-14 17:27:51', 0),
(73, 2035, 1000, 1, 10, '2021-06-14 17:42:32', 12419),
(74, 2036, 1002, 1, 10, '2021-06-14 17:42:32', 12419),
(76, 2035, 1000, 1, 10, '2021-06-14 17:45:28', 12419),
(77, 2036, 1002, 1, 10, '2021-06-14 17:45:28', 12419),
(78, 2037, 1003, 1, 20, '2021-06-14 17:45:28', 13053),
(79, 2039, 1000, 2, 20, '2021-06-14 18:20:48', 19956),
(80, 2040, 1002, 1, 10, '2021-06-14 18:20:48', 19956),
(82, 2045, 1003, 1, 20, '2021-06-14 18:26:11', 21024),
(83, 2046, 1001, 1, 20, '2021-06-14 18:26:11', 21024),
(84, 2049, 1001, 1, 20, '2021-06-14 22:33:40', 3894),
(85, 2051, 1003, 1, 20, '2021-06-14 22:33:40', 3894),
(87, 2052, 1000, 2, 20, '2021-06-14 23:49:21', 18827),
(88, 2053, 1001, 1, 20, '2021-06-14 23:49:21', 18827),
(90, 2056, 1000, 1, 10, '2021-06-14 23:57:43', 20476),
(91, 2057, 1001, 1, 20, '2021-06-14 23:57:43', 20476),
(92, 2060, 1000, 2, 20, '2021-06-15 12:44:15', 6269),
(93, 2061, 1002, 3, 30, '2021-06-15 12:44:15', 6269),
(94, 2062, 1008, 4, 40, '2021-06-15 12:44:15', 6269),
(95, 2063, 1001, 1, 20, '2021-06-18 23:45:20', 11742),
(96, 2064, 1001, 1, 20, '2021-06-18 23:45:20', 12013),
(97, 2065, 1010, 1, 12, '2021-06-18 23:45:20', 12248),
(98, 2066, 1000, 1, 10, '2021-06-18 23:45:20', 32542),
(102, 2067, 1011, 1, 12, '2021-06-18 23:46:54', 19),
(103, 2068, 1001, 1, 20, '2021-06-20 16:49:00', 23710),
(104, 2069, 1001, 1, 20, '2021-06-20 16:50:54', 24138),
(105, 2070, 1006, 1, 10, '2021-06-20 16:51:58', 24347),
(106, 2071, 1010, 1, 12, '2021-06-20 16:53:13', 24553),
(107, 2072, 1011, 1, 12, '2021-06-20 16:54:30', 24834),
(108, 2073, 1008, 1, 10, '2021-06-20 16:58:22', 25539),
(109, 2074, 1000, 1, 10, '2021-06-20 16:58:53', 25644),
(110, 2075, 1001, 1, 20, '2021-06-20 16:58:53', 25644),
(111, 2076, 1008, 1, 10, '2021-06-20 16:58:53', 25644),
(112, 2078, 1000, 1, 10, '2021-06-20 17:17:12', 29167),
(113, 2079, 1013, 1, 20, '2021-06-20 17:17:12', 29167),
(114, 2082, 1000, 2, 20, '2021-06-20 17:51:50', 3172),
(115, 2083, 1002, 3, 30, '2021-06-20 17:51:50', 3172),
(116, 2084, 1008, 4, 40, '2021-06-20 17:51:50', 3172),
(117, 2090, 1008, 3, 30, '2021-06-21 00:01:45', 9942),
(118, 2091, 1011, 5, 60, '2021-06-21 00:01:45', 9942),
(120, 2097, 1001, 3, 60, '2021-06-21 00:09:55', 11739),
(121, 2098, 1007, 3, 60, '2021-06-21 00:09:55', 11739),
(122, 2099, 1013, 4, 80, '2021-06-21 00:09:55', 11739),
(123, 2103, 1000, 2, 20, '2021-07-02 22:00:37', 29860),
(124, 2104, 1002, 3, 30, '2021-07-02 22:00:37', 29860);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `administrator`
--
ALTER TABLE `administrator`
  ADD PRIMARY KEY (`ADMIN_ID`),
  ADD UNIQUE KEY `ADMINISTRATOR_PHONE_UQ` (`ADMIN_PHONE`);

--
-- Indexes for table `product`
--
ALTER TABLE `product`
  ADD PRIMARY KEY (`PRODUCT_ID`);

--
-- Indexes for table `purchase`
--
ALTER TABLE `purchase`
  ADD PRIMARY KEY (`PURCHASE_ID`);

--
-- Indexes for table `salerecord`
--
ALTER TABLE `salerecord`
  ADD PRIMARY KEY (`SALE_ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `product`
--
ALTER TABLE `product`
  MODIFY `PRODUCT_ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1024;

--
-- AUTO_INCREMENT for table `purchase`
--
ALTER TABLE `purchase`
  MODIFY `PURCHASE_ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2105;

--
-- AUTO_INCREMENT for table `salerecord`
--
ALTER TABLE `salerecord`
  MODIFY `SALE_ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=126;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
