
import yaml
import argparse
from arvore import *

def parse_node(node_dict):
    node_type = node_dict['type']
    value = node_dict.get('value')

    if node_type == 'NUMBER':
        return Number(value)
    elif node_type == 'BOOLEAN':
        return Boolean(value)
    elif node_type == 'IDENTIFIER':
        return Identifier(value)
    elif node_type == "STRING":
        return String(value)
    elif node_type == 'IDENTIFIER_DECL':
        decl_variables = []
        children = node_dict.get('children', [])
        i = 0
        while i < len(children):
            current = children[i]

            # Ensure the current child is an IDENTIFIER
            if current['type'] == 'IDENTIFIER':
                var_name = parse_node(current)
                var_expression = None

                # Check if the next child is an expression (not an identifier)
                if i + 1 < len(children) and children[i + 1]['type'] != 'IDENTIFIER':
                    var_expression = parse_node(children[i + 1])
                    i += 1  # Skip the expression node

                # Append the variable and its expression (if any)
                decl_variables.append((var_name.value, var_expression))
            i += 1  # Move to the next node
        return decl_variables


    elif node_type == "BINARY_OP":
        bin_op_node = BinOp(value)
        for child in node_dict.get('children', []):
            bin_op_node.children.append(parse_node(child))
        return bin_op_node
    elif node_type == "UNARY_OP":
            un_op_node = UnOp(value)
            # Check if 'children' exists and contains exactly one child
            children = node_dict.get('children', [])
            if len(children) != 1:
                raise ValueError(f"Unary operation '{value}' requires exactly one child node.")
            un_op_node.child = parse_node(children[0])  # Parse the single child
            return un_op_node

    elif node_type == "DECLARATION_STATEMENT":
        decl_node = DeclarationNode()
        for child in node_dict.get('children', []):
            if child['type'] == 'IDENTIFIER_DECL':
                variables = parse_node(child)
                decl_node.variables.extend(variables)
            elif child['type'] == 'TYPE':
                decl_node.var_type = child['value']
        return decl_node
    elif node_type == "ASSIGNMENT_STATEMENT":
        assign_node = AssignmentNode()
        children = node_dict.get('children', [])
        parse = True
        for child in children:
            if child['type'] == 'IDENTIFIER' and parse:
                parse = False
                var_name = parse_node(child)
            else:
                expression = parse_node(child)
                assign_node.assignments.append((var_name.value, expression))
        return assign_node
    
    elif node_type == "PROGRAM":
        program_node = Program()
        for statement in node_dict.get('children', []):
            program_node.statements.append(parse_node(statement))
        return program_node
    elif node_type == "EXHIBIT":
        exhibit_node = Exhibit()
        children = node_dict.get('children', [])
        if len(children) == 0 or children[0]['type'] != "STRING":
            raise ValueError("The first child of an EXHIBIT node must be a STRING.")
        
        exhibit_node.format_string = parse_node(children[0]).Evaluate({})[0]
        for child in children[1:]:
            exhibit_node.arguments.append(parse_node(child))
        return exhibit_node
    elif node_type == "FOR_STATEMENT":
        for_node = ForStatementNode()
        children = node_dict.get("children", [])

        if len(children) != 4:
            raise ValueError("FOR_STATEMENT node must have exactly 4 children: initialization, condition, update, and body.")

        # Parse initialization, condition, update, and body
        for_node.initialization = parse_node(children[0])
        for_node.condition = parse_node(children[1])
        for_node.update = parse_node(children[2])
        for_node.body = [parse_node(child) for child in children[3].get("children", [])]

        return for_node
    elif node_type == "IF_STATEMENT":
            if_node = IfStatementNode()
            children = node_dict.get("children", [])
            if_node.condition = parse_node(children[0])
            if_node.true_block = [parse_node(child) for child in children[1].get("children", [])]
            if_node.false_block = None
            if len(children) == 3:
                if_node.false_block = [parse_node(child) for child in children[2].get("children", [])]
            return if_node
    
    elif node_type == "WHILE_STATEMENT":
        while_node = WhileStatementNode()
        children = node_dict.get("children", [])

        if len(children) != 2:
            raise ValueError("WHILE_STATEMENT must have exactly 2 children: condition and body.")

        while_node.condition = parse_node(children[0])
        while_node.body = [parse_node(child) for child in children[1].get("children", [])]
        return while_node

    else:
        raise ValueError(f"Unknown node type: {node_type}")








def build_ast(ast_yaml):
    ast_nodes = []
    for node_dict in ast_yaml:
        ast_nodes.append(parse_node(node_dict))
    return ast_nodes


parser = argparse.ArgumentParser(description="Parse YAML and build an AST.")
parser.add_argument("file", help="Path to the YAML file")
args = parser.parse_args()

# Load the YAML file
with open(args.file, "r") as file:
    data = yaml.safe_load(file)

# Parse the AST from YAML
ast_yaml = data.get("AST", [])
symbol_table = SymbolTable()
ast = build_ast(ast_yaml)

# Evaluate or process the AST
for node in ast:
    node.Evaluate(symbol_table)