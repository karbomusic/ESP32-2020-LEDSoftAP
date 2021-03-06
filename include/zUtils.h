#include <Arduino.h>

namespace zUtils
{

    String getLongTime()
    {
        unsigned long currentMillis = millis();
        unsigned long seconds = currentMillis / 1000;
        unsigned long minutes = seconds / 60;
        unsigned long hours = minutes / 60;
        unsigned long days = hours / 24;
        currentMillis %= 1000;
        seconds %= 60;
        minutes %= 60;
        hours %= 24;
        String time = String(days) + "d " + String(hours) + ":" + String(minutes) + ":" + String(seconds) + ":" + String(currentMillis) + "ms";
        return time;
    }

    String getMidTime()
    {
        unsigned long currentMillis = millis();
        unsigned long seconds = currentMillis / 1000;
        unsigned long minutes = seconds / 60;
        unsigned long hours = minutes / 60;
        unsigned long days = hours / 24;
        currentMillis %= 1000;
        seconds %= 60;
        minutes %= 60;
        hours %= 24;
        String time = String(days) + "d " + String(hours) + ":" + String(minutes) + ":" + String(seconds) + "s ";
        return time;
    }

    String getShortTime()
    {
        unsigned long currentMillis = millis();
        unsigned long seconds = currentMillis / 1000;
        unsigned long minutes = seconds / 60;
        unsigned long hours = minutes / 60;
        unsigned long days = hours / 24;
        currentMillis %= 1000;
        seconds %= 60;
        minutes %= 60;
        hours %= 24;
        String time = String(days) + "d " + String(hours) + "h " + String(minutes) + " m";
        return time;
    }

    String getMinSec()
    {
        unsigned long currentMillis = millis();
        unsigned long seconds = currentMillis / 1000;
        unsigned long minutes = seconds / 60;
        currentMillis %= 1000;
        seconds %= 60;
        minutes %= 60;
        String time = String(minutes) + "m " + String(seconds) + "s ";
        return time;
    }

    void getChipInfo()
    {
        Serial.println("ESP Chip Model: " + String(ESP.getChipModel()));
        Serial.println("CPU Frequency: " + String(ESP.getCpuFreqMHz()));
        Serial.println("Free Heap Mem: " + String(ESP.getFreeHeap()));
        Serial.println("Flash Mem Size: " + String(ESP.getFlashChipSize() / 1024 / 1024));
        Serial.println("Chip ID:" + String((uint32_t)ESP.getEfuseMac(), HEX));
    }

    String getChipID()
    {
        return String((uint32_t)ESP.getEfuseMac(), HEX);
    }

    // this function splits a string and returns an array of strings
    String *splitHSVParams(String str, char delimiter, int count)
    {
        int str_len = str.length();
        int delimiter_count = 0;
        int start = 0;
        int end = 0;
        for (int i = 0; i < str_len; i++)
        {
            if (str.charAt(i) == delimiter)
            {
                delimiter_count++;
            }
        }
        count = delimiter_count + 1;
        String *arr = new String[count];
        for (int i = 0; i < count; i++)
        {
            end = str.indexOf(delimiter, start);
            if (end == -1)
            {
                end = str_len;
            }
            arr[i] = str.substring(start, end);
            start = end + 1;
        }
        return arr;
    }
}