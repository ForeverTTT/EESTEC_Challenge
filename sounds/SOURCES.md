# Siren Audio Sources

Downloaded on 2026-06-06 for emergency-vehicle direction-of-arrival experiments.

MP3 files with the same base names are Wikimedia transcodes of the corresponding OGG originals.

## Recommended primary candidates

1. `wws_fireengine_siren.ogg`
   - Source: https://commons.wikimedia.org/wiki/File:WWS_Fireenginesiren.ogg
   - Original file: Ogg Vorbis, about 26 s.
   - License: Creative Commons Attribution 4.0 International.
   - Attribution: Work With Sounds / Konrad Gutkowski, Jonathan Nicolai.
   - Why: clear fire-engine tone sequence, good duration, strong periodic structure.

2. `wws_firetruck_siren_inside.ogg`
   - Source: https://commons.wikimedia.org/wiki/File:WWS_Firetruckssirenfrominside.ogg
   - Original file: Ogg Vorbis, about 42 s.
   - License: Creative Commons Attribution 4.0 International.
   - Attribution: Work With Sounds / Werstas.
   - Why: long fire-truck recording, useful as a second candidate if the first one is too monotonic.

3. `wws_policecar_siren.ogg`
   - Source: https://commons.wikimedia.org/wiki/File:WWS_Policecarsiren.ogg
   - Original file: Ogg Vorbis, about 16 s.
   - License: Creative Commons Attribution 4.0 International.
   - Attribution: Work With Sounds / Konrad Gutkowski.
   - Why: clean two-tone emergency siren with obvious modulation.

## Short loopable candidates

4. `ambulance_sound_1.wav`
   - Source: https://commons.wikimedia.org/wiki/File:AmbulanceSound1.wav
   - Original file: WAV, about 4.1 s.
   - License: Creative Commons Attribution-ShareAlike 4.0 International.
   - Attribution: Demircimehmed.
   - Why: short, clean ambulance sound; loop before playback if used for longer data collection.

5. `ambulance_sound_2.wav`
   - Source: https://commons.wikimedia.org/wiki/File:Ambulance_Sounds2.wav
   - Original file: WAV, about 5.9 s.
   - License: Creative Commons Attribution-ShareAlike 4.0 International.
   - Attribution: Demircimehmed.
   - Why: short, clean ambulance sound; loop before playback if used for longer data collection.

## Secondary candidate

6. `american_police_siren_pd.ogg`
   - Source: https://commons.wikimedia.org/wiki/File:American_police_siren_i.ogg
   - Original file: Ogg Vorbis, about 29 s.
   - License: Public domain.
   - Attribution: lezer, via PDSounds.
   - Why: longer emergency-siren recording, but it includes city ambience, so use it after testing the cleaner options above.

## Practical note

For the challenge, use one selected file consistently for every direction and for the final test. Start with `wws_fireengine_siren.ogg`; if it does not separate the directions well, try `wws_policecar_siren.ogg` next.

## Synthetic beacon

`chirp_beacon_600_3500hz_100ms_gap20ms_2min.wav`

- Generated locally for the challenge.
- Format: WAV PCM, 44.1 kHz, 16-bit, mono, 120 s.
- Pattern: repeated linear chirp from 600 Hz to 3500 Hz, 100 ms chirp plus 20 ms gap.
- Why: wideband, highly repeatable, and friendly to two-microphone direction learning.
- Practical note: play it from one physical speaker only. Avoid stereo speaker pairs, surround effects, or laptop speakers spread far apart.

`chirp_beacon_600_3500hz_100ms_gap20ms_2min.mp3`

- Local MP3 transcode of the WAV beacon above.
- Format: MP3, 44.1 kHz, mono, 192 kbps, about 120 s.
