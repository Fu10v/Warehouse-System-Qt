# Warehouse System

## About the project
"Warehouse System" is a software product designed to automate work with a database of goods arriving at an enterprise's warehouse. The system is designed to replace outdated paper methods of maintaining warehouse records, ensuring reliable data storage and operational access to them. The project was created as part of a coursework in the discipline of "Programming".

## Technology stack
* **Programming language:** C++[cite: 1].
* **Graphical user interface:** Qt library (Qt Widgets module).
* **Database:** Document-oriented database MongoDB.
* **DB drivers:** `mongo-cxx-driver` and `bsoncxx`.
* **Architecture:** The project is based on the principles of object-oriented programming (OOP). The Singleton pattern is used for the database management class and a modification of the Model-View pattern for working with tables.

## Main functionality
* **Authorization and role system:** Separation of access rights for the roles "Manager" (full access) and "Storekeeper" (limited access).
* **Product management (CRUD):** Ability to add, edit and delete records of receipt of goods (article, name, quantity, price, date, supplier).
* **Instant search:** Real-time filtering of product items by name or article using `QSortFilterProxyModel`.
* **Analytical reporting:** Automatic calculation of the total cost of the warehouse and visualization of the dynamics of receipts in the form of graphs (using the `QtCharts` module).

## Prerequisites
* **Operating system:** Microsoft Windows 10 (1809+) or Windows 11 (64-bit only).
* **System components:** Microsoft Visual C++ Redistributable 2015-2022.
* **Database:** MongoDB Community Server installed (versions 6.0 or 7.0).

## Deployment and configuration
1. **DB configuration:** Install MongoDB and be sure to configure it to run as a Windows service (Install MongoD as a Service). Make sure that port `27017` is open.
2. **Start the project:** Clone the repository and open the project in Qt Creator.
3. **Libraries:** For successful compilation and launch, make sure that the dynamic driver libraries (`mongocxx.dll`, `bsoncxx.dll`) and the required Qt libraries (`Qt6Core.dll`, `Qt6Widgets.dll`, etc.) are in the directory of the compiled `.exe` file.
4. **First start:** At the first start, the program will try to connect to `localhost:27017` and automatically initialize the necessary collections in the database. If necessary, the connection parameters can be changed through the program menu "Connection" -> "Connect to Database".

## Contact
Author: Petro Luchaninov
Email: luchaninovp5@gmail.com

## Preview

<img width="371" height="586" alt="image" src="https://github.com/user-attachments/assets/25f683a9-ec1c-4878-bf89-4b4d0fab84a1" />
<img width="917" height="578" alt="image" src="https://github.com/user-attachments/assets/7798e647-0bc4-45d9-8246-a4a7721aae96" />
<img width="888" height="563" alt="image" src="https://github.com/user-attachments/assets/3df34b24-56b0-48fb-b481-e411ee801ba0" />
<img width="439" height="582" alt="image" src="https://github.com/user-attachments/assets/f00ae1c5-5b11-4813-aa9e-ad8150969f9c" />
<img width="783" height="619" alt="image" src="https://github.com/user-attachments/assets/b59fe705-e0f4-4373-81c7-663650e84637" />
<img width="499" height="413" alt="image" src="https://github.com/user-attachments/assets/697ffa42-f4c3-44b8-8c33-52cbc7d2b486" />

