```mermaid

classDiagram

class OfficeMachine {
    <<interface>>
    +print(doc)
    +scan(doc)
    +fax(doc)
}

class SimplePrinter {
    +print(doc)
    +scan(doc)
    +fax(doc)
}

class MultifunctionalDevice {
    +print(doc)
    +scan(doc)
    +fax(doc)
}

OfficeMachine <|.. SimplePrinter
OfficeMachine <|.. MultifunctionalDevice

```
