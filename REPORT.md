# Отчёт по проекту mysyslog

## 1. Сборка проекта

1. Откройте командную строку (cmd или PowerShell) в корне проекта.
2. Выполните команду:
   ```
   make
   ```
   Это соберёт все библиотеки, драйверы, клиент и демон.

---

## 2. Тестирование

### 2.1. Тестирование mysyslog-client

**Пример команды для текстового драйвера:**
```
libmysyslog-client\mysyslog-client.exe -m "Hello, log!" -l 1 -d 0 -f 0 -p mylog.txt
```
**Пример вывода:**
```
Сообщение успешно записано в лог.
```
**Содержимое mylog.txt:**
```
1717000000 INFO example-app Hello, log!
```

**Пример команды для JSON-драйвера:**
```
libmysyslog-client\mysyslog-client.exe -m "Error in system" -l 3 -d 1 -f 0 -p mylog.json
```
**Пример вывода:**
```
Сообщение успешно записано в лог.
```
**Содержимое mylog.json:**
```
{"timestamp":1717000001,"log_level":"ERROR","process":"example-app","message":"Error in system"}
```

---

### 2.2. Тестирование mysyslog-daemon

1. Создайте файл конфигурации `mysyslog.cfg`:
   ```
   path=daemon.log
   driver=1
   format=0
   ```
2. Запустите демон:
   ```
   libmysyslog-daemon\mysyslog-daemon.exe mysyslog.cfg
   ```
3. Остановите демон сочетанием Ctrl+C.
4. Проверьте содержимое файла `daemon.log`.

**Пример вывода в консоли:**
```
[mysyslog-daemon] daemon message #1
[mysyslog-daemon] daemon message #2
[mysyslog-daemon] daemon message #3
...
Демон завершён.
```

**Пример содержимого daemon.log (json):**
```
{"timestamp":1717000002,"log_level":"DEBUG","process":"example-app","message":"daemon message #1"}
{"timestamp":1717000004,"log_level":"INFO","process":"example-app","message":"daemon message #2"}
{"timestamp":1717000006,"log_level":"WARN","process":"example-app","message":"daemon message #3"}
...
```

---

## 3. Структура проекта
- libmysyslog — основная библиотека логирования
- libmysyslog-text — драйвер вывода в текстовом формате (DLL)
- libmysyslog-json — драйвер вывода в формате JSON (DLL)
- libmysyslog-client — тестовое приложение для логирования
- libmysyslog-daemon — демон, пишущий логи по конфигу
- mysyslog-meta — (зарезервировано для Linux-метапакета)

## 4. Возможности
- Логирование сообщений с разными уровнями (DEBUG, INFO, WARN, ERROR, CRITICAL)
- Поддержка плагинов-драйверов (text, json)
- Гибкая настройка через параметры и конфиг
- Сборка и запуск на Windows

---

**Проект готов к тестированию и дальнейшему развитию!** 