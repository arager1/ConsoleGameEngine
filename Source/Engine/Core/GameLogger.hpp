#ifndef ENGINE_GAMELOGGER_HPP
#define ENGINE_GAMELOGGER_HPP


#ifdef LOGGING_ENABLED
#include <string>
#include <fstream>
#include <vector>
#endif

namespace Engine
{

namespace Logging
{

#ifdef LOGGING_ENABLED
using GameLogBuffer = std::vector<std::string>;
static GameLogBuffer g_logBuffer;
#endif

void clearLogFile()
{
#ifdef LOGGING_ENABLED
    try
    {
        std::ofstream logFile{LOG_FILE};
        logFile.close();
    }
    catch(const std::exception& exception)
    {
        // Cannot open log file
        throw exception;
    }
#endif
}


void writeMessageBufferToLogFile()
{
#ifdef LOGGING_ENABLED
    if (!g_logBuffer.empty())
    {
        std::ofstream logFile{LOG_FILE, std::ios_base::in | std::ios_base::app};

        for (const auto& message : g_logBuffer) logFile << message << "\n";

        logFile.close();

        g_logBuffer.clear();
    }
#endif
}


void logMessage(const std::string& message)
{
#ifdef LOGGING_ENABLED
    g_logBuffer.push_back(message);
#endif
}


} // namespace Logging


} // namespace Engine


#endif // ENGINE_GAMELOGGER_HPP
