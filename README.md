# Observer Pattern Implementation

This is a simple implementation of the observer pattern.
The Publisher is the observer and each subscriber (client) must inherit from ClientBase. 
In this implementation one client can send an event to all the other clients that are subscribed to the same event.

## Limitations

The implementation is very limited (quick and dirty). It doesn't have an event queue, dispatcher, etc.

