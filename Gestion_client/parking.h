#ifndef PARKING_H
#define PARKING_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>




class parking
{
public:
    parking();
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);//envoyer les données vers arduino
    QByteArray read_from_arduino();//recevoir les données de la carte arduino
    QSerialPort* getserial();
    QString getarduino_port_name();

 private:
    QSerialPort * serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;

 };

#endif // PARKING_H
