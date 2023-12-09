#ifndef _COLORS
#define _COLORS
/// A small function to printf colors and style to the console
///
/// Params:
///     msg The message to print, with a specific format
///
///     Examples of strings to give:
///     * "A message"
///     * "A [bold]bold message[/bold]"
///     * "A [bold]bold[/bold] and [italic]italic[/italic]
///             [cyan]cyan[/cyan] message"
void print(char *msg);
#endif
