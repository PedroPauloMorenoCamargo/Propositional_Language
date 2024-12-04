from abc import ABC, abstractmethod
import re

class SymbolTable:
    def __init__(self):
        # Dicionário para armazenar as variáveis
        self.symbols = {}

    def get(self, name):
        # Retorna o valor da variável se ela existir caso contrário, levanta um erro
        if name in self.symbols:
            return self.symbols[name]
        else:
            raise ValueError(f"Undefined variable '{name}'")

    def set(self, name, value_type):
        # Define o valor da variável
        self.symbols[name] = value_type


class Node(ABC):
    def __init__(self, value=None):
        self.value = value
        self.children = []

    @abstractmethod
    def Evaluate(self):
        pass

class Number(Node):
    def __init__(self, value):
        super().__init__(value)

    def Evaluate(self,symbol_table):
        return self.value, 'int'
    
class String(Node):
    def __init__(self, value):
        super().__init__(value)
    def Evaluate(self,symbol_table):
        return self.value, 'string'


class Boolean(Node):
    def __init__(self, value):
        super().__init__(value)
    
    def Evaluate(self, symbol_table):
        return self.value, 'log'
    

class BinOp(Node):
    def __init__(self, op=None):
        super().__init__(op)
        self.children = []
    def Evaluate(self, symbol_table):
        # Evaluate left and right children
        left_value, left_type = self.children[0].Evaluate(symbol_table)
        right_value, right_type = self.children[1].Evaluate(symbol_table)

        # Define possible operations
        operations = {
            'plus': self._handle_plus,
            'minus': self._handle_minus,
            'mult': self._handle_mult,
            'div': self._handle_div,
            'and': self._handle_and,
            'or': self._handle_or,
            'implication': self._handle_implication,
            'biconditional': self._handle_biconditional,
            'equal':  self._handle_equal,
            "greater": self._handle_greater,
            "lesser": self._handle_lesser
        }

        # Validate the operator and execute the corresponding function
        if self.value in operations:
            return operations[self.value](left_value, left_type, right_value, right_type)
        else:
            raise ValueError(f"Unknown binary operator: {self.value}")

    def _check_numeric(self, left_type, right_type):
        """Ensure both operands are numeric (not logical types)."""
        if left_type == "log" or right_type == "log":
            raise TypeError(
                f"Invalid arithmetic operation: {left_type} {self.value} {right_type}. "
                "Arithmetic operations do not support logical types ('log'). Ensure both operands are numeric."
            )
        return
    
    def _convert_to_logical(self, value):
        """Convert the numeric result to 'verum' or 'falsum'."""
        return "verum" if value else "falsum"

    def _handle_plus(self, left_value, left_type, right_value, right_type):
        self._check_numeric(left_type, right_type)
        return left_value + right_value, 'int'

    def _handle_minus(self, left_value, left_type, right_value, right_type):
        self._check_numeric(left_type, right_type)
        return left_value - right_value, 'int'

    def _handle_mult(self, left_value, left_type, right_value, right_type):
        self._check_numeric(left_type, right_type)
        return left_value * right_value, 'int'

    def _handle_div(self, left_value, left_type, right_value, right_type):
        self._check_numeric(left_type, right_type)
        if right_value == 0:
            raise ZeroDivisionError("Division by zero is not allowed.")
        return left_value // right_value, 'int'

    def _handle_and(self, left_value, left_type, right_value, right_type):
        """Logical AND operation."""
        # Convert logical types to numeric equivalents
        left_value = 1 if left_value == "verum" else 0 if left_type == "log" else left_value
        right_value = 1 if right_value == "verum" else 0 if right_type == "log" else right_value

        # Perform logical AND operation
        result = left_value and right_value
        return self._convert_to_logical(result), 'log'    
    
    def _handle_or(self, left_value, left_type, right_value, right_type):
        """Logical AND operation."""
        # Convert logical types to numeric equivalents
        left_value = 1 if left_value == "verum" else 0 if left_type == "log" else left_value
        right_value = 1 if right_value == "verum" else 0 if right_type == "log" else right_value

        # Perform logical AND operation
        result = left_value or right_value
        return self._convert_to_logical(result), 'log' 
    
    def _handle_implication(self, left_value, left_type, right_value, right_type):
        """Logical AND operation."""
        # Convert logical types to numeric equivalents
        left_value = 1 if left_value == "verum" else 0 if left_type == "log" else left_value
        right_value = 1 if right_value == "verum" else 0 if right_type == "log" else right_value

        # Perform logical AND operation
        result = not(left_value) or right_value
        return self._convert_to_logical(result), 'log' 
    
    def _handle_biconditional(self, left_value, left_type, right_value, right_type):
        """Logical AND operation."""
        # Convert logical types to numeric equivalents
        left_value = 1 if left_value == "verum" else 0 if left_type == "log" else left_value
        right_value = 1 if right_value == "verum" else 0 if right_type == "log" else right_value

        # Perform logical AND operation
        result = left_value == right_value
        return self._convert_to_logical(result), 'log'
    
    def _handle_equal(self, left_value, left_type, right_value, right_type):
        self._check_numeric(left_type, right_type)
        return self._convert_to_logical(left_value == right_value), "log"
    
    def _handle_greater(self, left_value, left_type, right_value, right_type):
        self._check_numeric(left_type, right_type)
        return self._convert_to_logical(left_value > right_value), "log"
    
    def _handle_lesser(self, left_value, left_type, right_value, right_type):
        self._check_numeric(left_type, right_type)
        return self._convert_to_logical(left_value < right_value), "log"
    
class UnOp(Node):
    def __init__(self, op=None):
        super().__init__(op)
        self.child = None  # Unary operations have a single child

    def Evaluate(self, symbol_table):
        # Evaluate the single child node
        value, value_type = self.child.Evaluate(symbol_table)

        # Define possible unary operations
        operations = {
            'not': self._handle_not,
            'minus': self._handle_minus,
            'plus': self._handle_plus
        }

        # Validate the operator and execute the corresponding function
        if self.value in operations:
            return operations[self.value](value, value_type)
        else:
            raise ValueError(f"Unknown unary operator: {self.value}")

    def _convert_to_logical(self, value):
        """Convert the numeric result to 'verum' or 'falsum'."""
        return "verum" if value else "falsum"

    def _handle_not(self, value, value_type):
        if value_type == "log":
            result = value != "verum"
        else:
            result = not value
        return self._convert_to_logical(result), "log"

    def _handle_minus(self, value, value_type):
        if value_type == "log":
            raise TypeError(f"Unary operator minus is not supported for logical variables '{value_type}'.")
        return -value, "int"
    def _handle_plus(self, value, value_type):
        if value_type == "log":
            raise TypeError(f"Unary operator plus is not supported for logical variables '{value_type}'.")
        return +value, 'int'
    

class Program(Node):
    def __init__(self):
        super().__init__()
        self.statements = []

    def Evaluate(self, symbol_table):
        """Evaluate all child statements in sequence."""
        results = []
        for statement in self.statements:
            result = statement.Evaluate(symbol_table)
            results.append(result)
        return results  


class Exhibit:
    def __init__(self):
        self.format_string = None
        self.arguments = []

    def Evaluate(self, symbol_table):
        # Avalie os argumentos
        evaluated_arguments = [arg.Evaluate(symbol_table) for arg in self.arguments]
        values, types = zip(*evaluated_arguments) if evaluated_arguments else ([], [])

        # Defina um mapeamento de placeholders para tipos esperados
        placeholder_map = {
            '%d': 'int',
            '%l': 'log'  
        }

        # Encontre placeholders na string de formatação
        placeholders = re.findall(r'%[dl]', self.format_string)


        # Valide o número de placeholders em relação ao número de argumentos
        if len(placeholders) != len(values):
            raise ValueError(
                f"Format string '{self.format_string}' expects {len(placeholders)} arguments, "
                f"but {len(values)} were provided."
            )

        # Valide os tipos dos argumentos
        for i, (placeholder, arg_type) in enumerate(zip(placeholders, types)):
            expected_type = placeholder_map.get(placeholder)
            if not expected_type:
                raise ValueError(f"Unsupported placeholder '{placeholder}' in format string.")
            if arg_type != expected_type:
                raise TypeError(
                    f"Argument {i+1} in format string '{self.format_string}' expects type '{expected_type}', "
                    f"but got type '{arg_type}'."
                )

        # Substitua '%l' por '%s' na string de formatação
        format_string = self.format_string.replace('%l', '%s')

        # Converta valores para o formato apropriado (ex: 'log' -> str)
        formatted_values = [
            str(value) if placeholder == '%l' else value for value, placeholder in zip(values, placeholders)
        ]

        print(format_string % tuple(formatted_values))

        return None, None



    

class Identifier(Node):
    def __init__(self, value):
        super().__init__(value)

    def Evaluate(self, symbol_table):
        return symbol_table.get(self.value)


class DeclarationNode(Node):
    def __init__(self):
        super().__init__()
        self.variables = []  # List of (name, expression) pairs
        self.var_type = None  # Type of the declared variables

    def Evaluate(self, symbol_table):
        for var_name, expression in self.variables:
            if var_name in symbol_table.symbols:
                raise ValueError(f"Redeclaration of the variable: {var_name}")
            if expression is not None:
                value, value_type = expression.Evaluate(symbol_table)
                if value_type != self.var_type:
                    raise TypeError(
                        f"Variable '{var_name}' is declared as '{self.var_type}', "
                        f"but got a value of type '{value_type}'."
                    )
                symbol_table.set(var_name, (value, value_type))
            else:
                default_value = self._get_default_value(self.var_type)
                symbol_table.set(var_name, (default_value, self.var_type))
        return None, None

    @staticmethod
    def _get_default_value(var_type):
        if var_type == "int":
            return 0
        elif var_type == "log":
            return "falsum"
        else:
            raise ValueError(f"Unsupported variable type: {var_type}")
        
class AssignmentNode(Node):
    def __init__(self):
        super().__init__()
        self.assignments = []

    def Evaluate(self, symbol_table):
        for var_name, expression in self.assignments:
            if var_name not in symbol_table.symbols:
                raise ValueError(f"Assignment without declaration of variable: {var_name}")
            # Evaluate the expression
            value, value_type = expression.Evaluate(symbol_table)
            # Get the current type of the variable
            current_value, current_type = symbol_table.get(var_name)
            # Type check
            if current_type != value_type:
                raise TypeError(
                    f"Cannot assign a value of type '{value_type}' to variable '{var_name}' of type '{current_type}'."
                )
            # Update the symbol table
            symbol_table.set(var_name, (value, current_type))
        return None, None

    
class IfStatementNode(Node):
    def __init__(self):
        super().__init__()
        self.condition = None
        self.true_block = None 
        self.false_block = None 

    def Evaluate(self, symbol_table):
        # Evaluate the condition
        condition_value, condition_type = self.condition.Evaluate(symbol_table)
        if condition_type != 'log':
            raise TypeError(f"Condition in IF statement must be logical (type 'log'), got '{condition_type}'.")

        # Convert logical values to Python boolean
        condition_met = condition_value == "verum"

        # Execute the appropriate block
        if condition_met:
            if self.true_block:
                for statement in self.true_block:
                    statement.Evaluate(symbol_table)
        elif self.false_block != None:
            if self.false_block:
                for statement in self.false_block:
                    statement.Evaluate(symbol_table)
        return None, None
    
class ForStatementNode(Node):
    def __init__(self):
        super().__init__()
        self.initialization = None  
        self.condition = None      
        self.update = None          
        self.body = []             
    def Evaluate(self, symbol_table):
        # 1. Execute initialization
        if self.initialization:
            self.initialization.Evaluate(symbol_table)

        # 2. Loop while the condition is true
        while True:
            # Evaluate condition
            condition_value, condition_type = self.condition.Evaluate(symbol_table)
            if condition_type != 'log':
                raise TypeError(f"Condition in FOR statement must evaluate to 'log', got '{condition_type}'.")
            if condition_value != "verum":
                break

            # Execute body
            for statement in self.body:
                statement.Evaluate(symbol_table)
            if self.update:
                self.update.Evaluate(symbol_table)
        return None, None


class WhileStatementNode(Node):
    def __init__(self):
        super().__init__()
        self.condition = None  # The condition to evaluate
        self.body = []         # List of nodes in the loop body

    def Evaluate(self, symbol_table):
        while True:
            # Execute the body first (do-while semantics)
            for statement in self.body:
                statement.Evaluate(symbol_table)

            # Evaluate the condition
            condition_value, condition_type = self.condition.Evaluate(symbol_table)
            if condition_type != "log":
                raise TypeError(f"Condition in WHILE statement must evaluate to 'log', got '{condition_type}'.")
            
            # Convert logical value to Python boolean
            if condition_value != "verum":
                break
        return None, None


    




    



