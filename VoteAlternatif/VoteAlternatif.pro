TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        alternativeVote.cpp \
        collectVotesAlt.cpp \
        countVotesAlt.cpp \
        createCandidatesAlt.cpp \
        createVotersAlt.cpp \
        main.cpp

HEADERS += \
    AlternativeVote.hpp \
    CollectVotesAlt.hpp \
    CountVotesAlt.hpp \
    CreateCandidatesAlt.hpp \
    CreateVotersAlt.hpp \
    structCandidates.hpp \
    structVoters.hpp
