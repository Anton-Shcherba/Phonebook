# Phonebook

Необходимо реализовать реализовать простой телефонный справочник.

### Описание
* Каждая запись в справочнике - это имя (строка без пробелов), например “John”, и семизначный номер телефона, состоящий только из цифр, например, 1234567. Номер телефона не может начинаться с 0.  
*  Для работы со справочником используется консоль. Необходимо реализовать обработку следующих команд:
  
    _**read <filename>**_ - прочитать (загрузить) данные из файла (формат хранения данных справочника в файле может быть любым). Вместо <filename> указывается путь к файлу.  
   _**add <name> <number>**_ - добавить запись в справочник. В случае, если имя или номер некорректны, необходимо вывести в консоль сообщение об ошибке. Если запись с таким именем уже существует, то новая заместит старую (номер будет перезаписан).  
   _**search <name>**_ - поиск записи с таким именем. Если запись найдена - выводим имя и номер телефона. Если запись не найдена - выводим соответствующее сообщение (например, “No entry with name <name> found.” или “Не найдено записи с именем <name>.”).  
   _**delete <name>**_ - удалить запись с таким именем. В случае, если удаление прошло успешно, необходимо вывести сообщение об это (например, “Successfully deleted.” или “Успешно удалено.”). Если записи с таким именем нет, вывести соответствующее сообщение (например, “No entry with name <name> found.” или “Не найдено записи с именем <name>.”).  
   _**write <filename>**_ - записать имеющиеся на текущий момент в памяти данные справочника в указанный файл. Формат записи должен быть таким, чтобы файл можно было прочитать, используя команду read. 

* Организовать хранение данных справочника в памяти необходимо таким образом, чтобы операции поиска, добавления и удаления были максимально эффективными. При этом приоритет - у операции поиска, как наиболее часто применяющейся (т.е. эффективность поиска важнее эффективности удаления/добавления). 
* При запуске программы желательно вывести справочный текст с кратким описанием поддерживаемых команд. 
* По желанию можно выводить сообщения и при успешном выполнении команд (например, запись успешно добавлена или успешно записано в файл / прочитано из файла). 

### Ожидаемый результат
1. Запускаем программу.
2. Видим в консоли описание поддерживаемых команд. 
3. Вводим команды (ответы программы выделены):  

   >add John 1234567  
    add Bart 0000000  
    **Invalid input.**  
    add Elly 9876543  
    add Mrs Green 1425374  
    **Invalid input.**  
    search Bart  
    **No entry with the name Bart found.**  
    search Elly  
    **Elly 9876543**   
    delete Bart  
    **No entry with the name Bart found.**  
    write “contacts.txt” 

4. Закрываем программу и запускаем опять: 
 
   >read “contacts.txt”  
   search John  
   **John 1234567**  
   search Elly  
   **Elly 9876543**