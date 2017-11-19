#ifndef TASKSENUM_H
#define TASKSENUM_H
#include <string>
#include <QDataStream>
#include <algorithm>
#include <QString>

class TaskEnum
{
public:
   enum Enum
   {
      wakeup = 0,
      eating,
      bathing,
      sleeping,
      playing,
      radio,
      tv,
      InvalidTask
   };

   // Constructors
   TaskEnum(void);
   TaskEnum(Enum ee);
   explicit TaskEnum(const QString& ss);

   // Overloaded assignment operators
   TaskEnum& operator = (const TaskEnum& cc);
   TaskEnum& operator = (const QString& ss);
   TaskEnum& operator = (Enum ee);

   // Overloaded comparison operators
   bool operator<  (const TaskEnum& cc) const;
   bool operator<  (Enum ee) const;
   bool operator<= (const TaskEnum& cc) const;
   bool operator<= (Enum ee) const;
   bool operator>  (const TaskEnum& cc) const;
   bool operator>  (Enum ee) const;
   bool operator>= (const TaskEnum& cc) const;
   bool operator>= (Enum ee) const;
   bool operator== (const TaskEnum& cc) const;
   bool operator== (const QString& ss) const;
   bool operator== (const Enum ee) const;
   bool operator!= (const TaskEnum& cc) const;
   bool operator!= (const QString& ss) const;
   bool operator!= (const Enum ee) const;

   // Accessor functions
   inline QString getString (void) const;
   inline Enum        getEnum   (void) const;
   inline int         getValue  (void) const;

private:
   // Static functions
   static Enum        fromString(QString ss);
   static QString toString(Enum ee);
   static int         toValue(Enum ee);

   // Data members
   Enum        m_enum;
   QString m_string;
   int         m_value;
};

inline QDataStream& operator<< (QDataStream& _os, const TaskEnum& _e)
{
   _os << _e.getString();
   return _os;
}

inline QString TaskEnum::getString(void) const
{
   return m_string;
}

TaskEnum::Enum TaskEnum::getEnum(void) const
{
   return m_enum;
}

int TaskEnum::getValue(void) const
{
   return m_value;
}



#endif // TASKSENUM_H
