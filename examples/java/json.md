# Пример использования библиотек для работы с JSON

# Jackson
```xml
<!-- Maven -->
<dependency>
    <groupId>com.fasterxml.jackson.core</groupId>
    <artifactId>jackson-databind</artifactId>
    <version>2.15.0</version>
</dependency>
```

```java
import com.fasterxml.jackson.databind.ObjectMapper;

public class JacksonExample {
    public static void main(String[] args) throws Exception {
        ObjectMapper mapper = new ObjectMapper();
        
        // Объект → JSON
        User user = new User("Alex", 30);
        String json = mapper.writeValueAsString(user);
        System.out.println("JSON: " + json); // {"name":"Alex","age":30}

        // JSON → Объект
        String inputJson = "{\"name\":\"Maria\",\"age\":25}";
        User parsedUser = mapper.readValue(inputJson, User.class);
        System.out.println("User: " + parsedUser.getName()); // Maria
    }
}

class User {
    private String name;
    private int age;
    
    // Геттеры/сеттеры и конструкторы
}
```


## Gson

```xml
<!-- Maven -->
<dependency>
    <groupId>com.google.code.gson</groupId>
    <artifactId>gson</artifactId>
    <version>2.10.1</version>
</dependency>
```


```java
import com.google.gson.Gson;

public class GsonExample {
    public static void main(String[] args) {
        Gson gson = new Gson();
        
        // Объект → JSON
        User user = new User("John", 28);
        String json = gson.toJson(user);
        System.out.println("JSON: " + json); // {"name":"John","age":28}

        // JSON → Объект
        String inputJson = "{\"name\":\"Anna\",\"age\":22}";
        User parsedUser = gson.fromJson(inputJson, User.class);
        System.out.println("User: " + parsedUser.getName()); // Anna
    }
}
```

См. также
- org.json 
