<?xml version="1.0" encoding="UTF-8"?>
<tileset version="1.4" tiledversion="1.4.2" name="character" tilewidth="50" tileheight="37" tilecount="112" columns="7">
 <image source="sprite_sheet.png" width="385" height="592"/>
 <tile id="0">
  <objectgroup draworder="index" id="2">
   <object id="2" name="character_idle" type="collision" x="19" y="6" width="12" height="30"/>
  </objectgroup>
  <animation>
   <frame tileid="0" duration="100"/>
   <frame tileid="1" duration="100"/>
   <frame tileid="2" duration="100"/>
   <frame tileid="3" duration="100"/>
  </animation>
 </tile>
 <tile id="4">
  <objectgroup draworder="index" id="2">
   <object id="1" name="character_ducking" type="collision" x="20" y="16" width="12" height="20"/>
  </objectgroup>
  <animation>
   <frame tileid="4" duration="100"/>
   <frame tileid="5" duration="100"/>
   <frame tileid="6" duration="100"/>
   <frame tileid="7" duration="100"/>
  </animation>
 </tile>
 <tile id="8">
  <objectgroup draworder="index" id="2">
   <object id="1" name="character_running" type="collision" x="25" y="9" width="10" height="27"/>
  </objectgroup>
  <animation>
   <frame tileid="8" duration="100"/>
   <frame tileid="9" duration="100"/>
   <frame tileid="10" duration="100"/>
   <frame tileid="11" duration="100"/>
   <frame tileid="12" duration="100"/>
   <frame tileid="13" duration="100"/>
  </animation>
 </tile>
 <tile id="14">
  <objectgroup draworder="index" id="2">
   <object id="1" name="lowering" type="collision" x="20" y="14" width="12" height="22"/>
  </objectgroup>
  <animation>
   <frame tileid="14" duration="100"/>
   <frame tileid="15" duration="100"/>
  </animation>
 </tile>
 <tile id="16">
  <objectgroup draworder="index" id="2">
   <object id="2" name="jumping" x="22" y="7" width="12" height="24"/>
  </objectgroup>
  <animation>
   <frame tileid="16" duration="100"/>
   <frame tileid="17" duration="100"/>
  </animation>
 </tile>
 <tile id="18">
  <objectgroup draworder="index" id="2">
   <object id="1" name="summersault" x="18" y="9" width="17" height="18"/>
  </objectgroup>
  <animation>
   <frame tileid="18" duration="100"/>
   <frame tileid="19" duration="100"/>
   <frame tileid="20" duration="100"/>
   <frame tileid="21" duration="100"/>
  </animation>
 </tile>
 <tile id="22">
  <objectgroup draworder="index" id="2">
   <object id="1" name="falling" x="23" y="6" width="10" height="24"/>
  </objectgroup>
  <animation>
   <frame tileid="22" duration="100"/>
   <frame tileid="23" duration="100"/>
  </animation>
 </tile>
</tileset>
