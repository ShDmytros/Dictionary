# __Словник__

### _Ця програма призначення для вивчення іноземних слів, але й може бути використана для вивчення термнів, формул тощо._

----------------

## __Опції__
1. Find a Words
2. Add new word
3. Delete a word
4. Edit a word
5. Show all words
6. Export Data
7. Delete All Data
8. Game 'Guess a word'
9. Exit

----------------

Ця програма підтримує можливість зберігати слова, за рахунок запису у файл данних 
з списку `map`, у файл `dictionary.data`. Вона має дві функції у класі `WorkingWithFiles`, 
під назвою `saveData(const map<string, string>& dict)` та `readData(map<string, string>& dict)`.
Під час кожного виклику головної функції `main_self()` _у класі `Menu`_, викликається функція 
`readData(map<string, string>& dict)`.

----------------

### __Find a Words__ _- знайти слово_
Якщо слів немає, виводиться напис:
>Sorry you don't have any words yet!

<br>

В іншому випадку програма запитує слово:
>Type a learning word that you want to find:

<br>

Якщо слово існує, програма видає нам слово на іноземній мові та на рідній:
>Apple - Яблуко

<br>

Якщо слово не існує:
>Sorry we couldn't found the word, maybe <br> it's not exist.


----------------

### __Add a new word__ _- додати нове слово_
В будь якому разі, нам спочатку буде виводитись рядок:
>Type a word from language that you study:

<br>

Якщо слово вже існує, нам виводиться:
>Word have already exists!

<br>

Якщо слова ще немає:
>Type a word from language that your native:

<br>
<br>

Також у будь якому разі у нас буде відбуватися зберігання цього слова за рахунок функції 
`saveData(const map<string, string>& dict)`.<br>

>Data saved successfully!

----------------

### __Delete a word__ _- видалити слово_
Якщо слів немає, виводиться напис:
>Sorry you don't have any words yet!

<br>

В іншому випадку нам виводиться:
>Type a word from language you study that you want to delete:

<br>

Якщо слово існує, програма його видаляє зі списку:
>Word deleted successfully!

>Data saved successfully!

<br>

Якщо слова немає:
>Word not found!


----------------

### __Edit a word__ _- відредагувати слово_
Якщо слів немає, виводиться напис:
>Sorry you don't have any words yet!

<br>

В іншому випадку нам виводиться:
>Type a learning word that you want to edit:

<br>

Якщо слово існує, користувач вводить новий переклад та значення перезаписується:
>Type a new translation of the word:

<br>

А після введення:
>Data saved successfully!

<br>

Якщо слова немає:
>Sorry we couldn't found the word, maybe 
<br> it's not exist, please type 2 and write it in this case.

----------------

### __Show all words__ _- показати усі слова_

Якщо слів немає, виводиться напис
>Sorry you don't have any words yet!

<br>

Якщо слова є, вони виводяться в форматі:
>Apple - Яблуко
<br>Book - Книга
<br>Computer - Комп'ютер
<br>Lamp - Лампа
<br>Paper - Папір
<br>Phone - Телефон
<br>World - Світ

----------------

### __Export Data__ _- експортувати данні_

Якщо слів немає, виводиться напис
>Sorry you don't have any words yet!

<br>

Якщо слова є, у користувача програма запитує розташування куди записати слова, і потрібно ввести шлях в форматі `D:\Files\New Folder`.
Якщо користувач хоче записати файл у папці з самоюю програмою, він повинен ввести 1
>Type where do you want to save the file, like 'D:\Files\New Folder'."
<br>if you want to save file in the program folder, just type 1:

<br>

Якщо користувач ввів 1 або правильний шлях, всі його слова експортуються в `.txt`, і тоді виводиться  напис:
>Data exported successfully! 

<br>

Якщо шлях був введений неправильно, виводиться помилка:
>Error, something went wrong!
<br>Maybe the way you typed is not exist!

----------------

### __Delete All Data__ _- видалити усі данні_

Якщо слів немає, виводиться напис
>Sorry you don't have any words yet!

<br>

Якщо слова є, програма просить підтвердити, чи точно впевнений користувач, 
у тому, що він хоче видалити усі данні:
>Are you sure, that you want to delete everything? (1 - Yes, 2 - No):

<br>

1. Якщо користувач підтвердив _(натиснув `1`)_, програма виводить:
   >Data have been deleted successfully!"

   та програма видаляє всі значення в контейнері `data`.

<br>

2. Якщо користувач передумав, виводиться:
   >Your choice is to not delete!
   
----------------

### __Game 'Guess a word'__ _- гра 'Вгадай слово'_

Якщо слів немає, виводиться напис
>Sorry you don't have any words yet!

<br>

Якщо слова є, програма виводить:
>Type '1' if you want to leave earlier!"

<br>

Потім у нас виводиться випадково обране слово:
>Translate a word 'Paper' into your native language:

<br>

Якщо слово введене правильно, нам виводиться:
>Congratulation! You are right!

В іншому випадку:
>You should study harder the word of Paper.

<br>

Функція закінчується

- якщо був введений 1
- або в копії контейнера `dict`, закінчилися слова, тоді в цьому випадку, нам виводиться:
  >Alright, you guessed all words!

----------------

##Взагалому це весь основний функціонал програми, для неї ще будуть доповнення та оновлення.
