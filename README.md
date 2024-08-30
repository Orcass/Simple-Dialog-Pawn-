# Simple-Dialog-Pawn-
Pre-Validation Hooks: Integrate global checks before processing any dialog response. Useful for validating conditions like player status before showing dialogs.
Default Callback Handling: Automatically handles dialogs without a registered callback, ensuring that all dialogs have a response handler.
Dialog Queue Management: Manage multiple dialogs for a single player by queuing dialogs if the player is already engaged in one.
Modular Design: Keep your code clean and organized by registering specific callbacks for each dialog and adding global validation hooks.

# Usage-
Include the Script: Place dialog_manager_advanced.inc in your includes directory and include it in your script.
Register Callbacks: Use RegisterDialogCallback(dialogid, callback) to associate a dialog ID with a callback function.
Handle Responses: Implement callback functions to handle player responses for each dialog.
Global Pre-Validation: Optionally, register a global validation function to perform checks before processing any dialog response.

Thankyou!!
