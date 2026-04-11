/*
  Server-side helper to transfer ownership of the AT-RT unit to the embarking player client.
  This makes selectPlayer more reliable in multiplayer if the AT-RT AI unit is server-local.
*/

if (!isServer) exitWith {};

params ["_atrt", "_ownerId"];
if (isNull _atrt) exitWith {};
_atrt setOwner _ownerId;