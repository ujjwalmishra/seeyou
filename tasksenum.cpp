#include <stdexcept>
#include "tasksenum.h"

// Constructors
TaskEnum::TaskEnum(void) :
   m_enum(wakeup),
   m_string("Woke Up"),
   m_value(0)
{}

TaskEnum::TaskEnum(Enum _e) :
   m_enum(_e),
   m_string(toString(_e)),
   m_value(0)
{}

TaskEnum::TaskEnum(const QString& _s) :
   m_enum(fromString(_s)),
   m_string(_s),
   m_value(toValue(m_enum))
{}

// Assignment operators

TaskEnum& TaskEnum::operator= (const TaskEnum& _c)
{
   m_string = _c.m_string;
   m_enum   = _c.m_enum;
   m_value  = _c.m_value;
   return *this;
}

TaskEnum& TaskEnum::operator= (const QString& _s)
{
   m_string = _s;
   m_enum   = fromString(_s);
   m_value  = toValue(m_enum);
   return *this;
}

TaskEnum& TaskEnum::operator= (Enum _e)
{
   m_enum   = _e;
   m_string = toString(_e);
   m_value  = toValue(_e);
   return *this;
}

bool TaskEnum::operator< (const TaskEnum& _c) const
{
   return (m_value < _c.m_value);
}

bool TaskEnum::operator< (Enum _e) const
{
   return (m_value < toValue(_e));
}

bool TaskEnum::operator<= (const TaskEnum& _c) const
{
   return (m_value <= _c.m_value);
}

bool TaskEnum::operator<= (Enum _e) const
{
   return (m_value <= toValue(_e));
}

bool TaskEnum::operator> (const TaskEnum& _c) const
{
   return (m_value > _c.m_value);
}

bool TaskEnum::operator> (Enum _e) const
{
   return (m_value > toValue(_e));
}

bool TaskEnum::operator>= (const TaskEnum& _c) const
{
   return (m_value >= _c.m_value);
}

bool TaskEnum::operator>= (Enum _e) const
{
   return (m_value >= toValue(_e));
}

bool TaskEnum::operator== (const TaskEnum& _c) const
{
   return (m_enum == _c.m_enum);
}

bool TaskEnum::operator== (const QString& _s) const
{
   return (m_string == _s);
}

bool TaskEnum::operator== (const Enum _e) const
{
   return (m_enum == _e);
}

bool TaskEnum::operator!= (const TaskEnum& _c) const
{
   return (m_enum != _c.m_enum);
}

bool TaskEnum::operator!= (const QString& _s) const
{
   return (m_string != _s);
}

bool TaskEnum::operator!= (const Enum _e) const
{
   return (m_enum != _e);
}

TaskEnum::Enum TaskEnum::fromString(QString _s)
{
   // Case insensitive - make all upper case
   //std::transform(_s.begin(), _s.end(), _s.begin(), toupper);
   _s = _s.toUpper();
   if(_s == "WAKEUP")         return wakeup;
   else if(_s == "EATING")    return eating;
   else if(_s == "BATHING")   return bathing;
   else if(_s == "SLEEPING") return sleeping;
   else if(_s == "PLAYING")  return playing;
   else if(_s == "RADIO")    return radio;
   else if(_s == "TV")  return tv;

   //throw std::range_error("Not a valid Day value: " + _s);
   return InvalidTask;
};

QString TaskEnum::toString(TaskEnum::Enum _e)
{
   switch (_e)
   {
      case wakeup:    { return "WAKEUP";    }
      case eating:    { return "EATING";    }
      case bathing:   { return "BATHING";   }
      case sleeping: { return "SLEEPING"; }
      case playing:  { return "PLAYING";  }
      case radio:    { return "RADIO";    }
      case tv:  { return "TV";  }
   }
   return "InvalidTask";
}

int TaskEnum::toValue(TaskEnum::Enum _e)
{
   switch (_e)
   {
      case wakeup:    { return 0; }
      case eating:    { return 2; }
      case bathing:   { return 3; }
      case sleeping: { return 4; }
      case playing:  { return 5; }
      case radio:    { return 6; }
      case tv:  { return 7; }
   }
   return 8;  // Invalid
}
